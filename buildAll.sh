: '
buildAll.sh - Automated Build Script for Multiple FORTE trace Configurations

This script automates the process of building several configurations in 4diac FORTE,
each corresponding to a specific trace scenario. It checks out the appropriate git branch,
applies trace configuration-specific CMake parameters, and compiles the binaries into dedicated folders.

Usage:
  ./buildAll.sh [ARCHITECTURE]
    ARCHITECTURE - Optional. Target architecture for the build (default: Posix).

Main Features:
- Defines mappings between trace configuration folders, git branches, and CMake parameters.
- Iterates through each configuration:
    - Creates a dedicated binary output folder.
    - Checks out the required git branch in the FORTE source directory.
    - Runs CMake with both common and configuration-specific parameters.
    - Builds the project.
    - Measures and reports the build time for each configuration.
- Summarizes total build time for all configurations.

Output:
- Binaries for each configuration are placed in BIN_FOLDER/<configuration>.
- Execution time for each build and the total time are reported at the end.

Requirements:
- Bash 4+ (for associative arrays)
- git
- cmake
- make
'
#!/bin/bash

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
FORTE_FOLDER="$SCRIPT_DIR/4diac-forte" # Path to the FORTE source directory
MODULES_FOLDER="$SCRIPT_DIR/forteModules" # Path to external FORTE modules
BIN_FOLDER="$SCRIPT_DIR/bin" # Output directory for built binaries

# Parse architecture parameter (default to Posix)
ARCHITECTURE="Posix"
if [ $# -ge 1 ]; then
  ARCHITECTURE="$1"
fi

# === CONFIGURATION ===

# Declare an associative array mapping folders to their git branches
declare -A folder_branches=(
  ["performanceNotTraced"]="trace-only-sifb~" # one commit before removing all extra traces
  ["performanceClassic"]="trace-only-sifb~" # one commit before removing all extra traces
  ["performanceOnlySIFB"]="trace-only-sifb"
  ["performanceBinary"]="trace-binary"
  ["performanceNoTypeOrClock"]="trace-no-type-or-clock"
  ["performanceImprovements"]="trace-improvements"
  ["performanceAnotherThread"]="trace-another-thread"
)

# Declare an associative array mapping folders to their cmake parameters
declare -A folder_cmake_params=(
  ["performanceNotTraced"]=""
  ["performanceClassic"]="-DFORTE_TRACE_CTF=ON"
  ["performanceOnlySIFB"]="-DFORTE_TRACE_CTF=ON -DFORTE_TRACE_CTF_REPLAY_DEBUGGING=ON"
  ["performanceBinary"]="-DFORTE_TRACE_CTF=ON -DFORTE_TRACE_CTF_REPLAY_DEBUGGING=ON"
  ["performanceNoTypeOrClock"]="-DFORTE_TRACE_CTF=ON -DFORTE_TRACE_CTF_REPLAY_DEBUGGING=ON"
  ["performanceImprovements"]="-DFORTE_TRACE_CTF=ON -DFORTE_TRACE_CTF_REPLAY_DEBUGGING=ON"
  ["performanceAnotherThread"]="-DFORTE_TRACE_CTF=ON -DFORTE_TRACE_CTF_REPLAY_DEBUGGING=ON"
)

# === FUNCTIONS ===

# 1. Create the bin folder if it doesn't exist
create_bin_folder() {
  local folder_name="$1"
  if ! mkdir -p "$folder_name"; then
    echo "Error: Failed to create folder $folder_name"
    exit 1
  fi
}

# 2. Checkout the specified git branch
checkout_branch() {
  local branch="$1"
  echo "Checking out branch: $branch"
  git -C "${FORTE_FOLDER}" checkout "$branch" || { echo "Failed to checkout branch: $branch"; exit 1; }
}

# 3. Run CMake with base command and folder-specific parameters
run_cmake() {
  local extra_params="$1"
  local build_folder="$2"
  echo "Running CMake with parameters: $extra_params"
  cmake -G "Unix Makefiles" \
    -DFORTE_ARCHITECTURE=$ARCHITECTURE \
    -DFORTE_COM_ETH=ON \
    -DFORTE_COM_FBDK=ON \
    -DFORTE_COM_LOCAL=ON \
    -DFORTE_TESTS=OFF \
    -DFORTE_MODULE_CONVERT=ON \
    -DFORTE_MODULE_IEC61131=ON \
    -DFORTE_MODULE_UTILS=ON \
    -DCMAKE_BUILD_TYPE=Release \
    -DFORTE_EXTERNAL_MODULES_DIRECTORY="$MODULES_FOLDER" \
    -DFORTE_MODULE_EXTERNAL_performance=ON \
    -DFORTE_LOGLEVEL=NOLOG \
    $extra_params \
    -B "$build_folder" \
    -S "$FORTE_FOLDER" || { echo "CMake failed"; exit 1; }

  make -C "$build_folder" -j8
}

# === MAIN LOOP ===
declare -A folder_times

for folder in "${!folder_branches[@]}"; do
  branch="${folder_branches[$folder]}"
  cmake_params="${folder_cmake_params[$folder]}"

  start_time=$(date +%s)

  create_bin_folder "${BIN_FOLDER}/$folder"
  checkout_branch "$branch"
  run_cmake "$cmake_params" "${BIN_FOLDER}/$folder"
  cd - > /dev/null  # return to the original directory silently

  end_time=$(date +%s)
  duration=$((end_time - start_time))
  folder_times["$folder"]=$duration
  echo ""
done

# === REPORT ===
echo "==== Execution Time Report ===="
total_time=0
for folder in "${!folder_times[@]}"; do
  time_spent=${folder_times[$folder]}
  echo "$folder: ${time_spent}s"
  total_time=$((total_time + time_spent))
done
echo "Total time: ${total_time}s"
