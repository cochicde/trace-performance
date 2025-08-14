###############################################################################
# Script Name: executeTests.sh
#
# Description:
#   This script automates the execution of performance tests for a set of 
#   system test files across multiple binary folders. It collects results 
#   and trace sizes, organizing outputs into structured result directories.
#
# Usage:
#   ./executeTests.sh systemTest1 systemTest2 -- folder1 folder2 ...
#
#   - systemTest1, systemTest2, ... : Paths to system fboot files to execute.
#   - folder1, folder2, ...         : Paths to binary folders containing
#                                     the executables and traces.
#   - '--'                          : Delimiter separating system tests and
#                                     performance folders.
#
# Functionality:
#   - Determines the script's and results directories.
#   - Iterates over each provided performance folder and system test file.
#   - Executes the test binary with appropriate parameters:
#       - For "NotTraced" tests, runs without trace generation.
#       - For other tests, generates traces and calculates their total size.
#   - Stores CSV results and trace sizes in organized result directories.
#   - Handles missing parameters with error messages.
#
# Output:
#   - Results are stored in $SCRIPT_DIR/results/<systemTestName>/<test>.csv
#   - Trace sizes are stored in $SCRIPT_DIR/results/<systemTestName>/<test>.size
#
# Requirements:
#   - Bash shell
#   - Executable 'forte' binary in each performance folder under ./src/
#
###############################################################################
#!/bin/bash

# Get the directory where the script is located
SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
BASE_RESULTS_FOLDER="$SCRIPT_DIR/results"

# Function to be executed in each performance folder
executeInEachFolder() {
  local folder="$1"

  for systemTest in "${systemTests[@]}"; do
    echo "Processing folder: $folder with system test: $systemTest"

    test="$(basename "$folder")"
    test="${test#performance}"

    resultsFolder="$BASE_RESULTS_FOLDER/$(basename "${systemTest%.*}")"
    mkdir -p "$resultsFolder"
    echo "Storing results in: $resultsFolder"

    cd "$folder"
    rm performanceCSV 2>/dev/null

    if [[ "$test" == "NotTraced" ]]; then
      echo "Special handling for performanceNotTraced"
      time ./src/forte -f "$SCRIPT_DIR/$systemTest"
    else
      mkdir -p ./traces/
      rm ./traces/* 2> /dev/null 
      time ./src/forte -t ./traces/ -f "$SCRIPT_DIR/$systemTest"

      # Calculate total size of files in ./traces in MB and save to file
      trace_size=$(du -sm ./traces | cut -f1)
      echo "$trace_size" > "$resultsFolder/${test}.size"
    fi

    mv performanceCSV "$resultsFolder/${test}.csv"
    cd "$SCRIPT_DIR"
  done
}

systemTests=()
folders=()
found_delimiter=0
for arg in "$@"; do
  if [[ "$arg" == "--" ]]; then
    found_delimiter=1
    continue
  fi
  if [[ $found_delimiter -eq 0 ]]; then
    systemTests+=("$arg")
  else
    folders+=("$arg")
  fi
done


# If no system test was provided, exit with an error message
if [ ${#systemTests[@]} -eq 0 ]; then
  echo "No system test was provided as parameter"
  exit 1
fi

# If no system test was provided, exit with an error message
if [ ${#folders[@]} -eq 0 ]; then
  echo "No executable folder was provided as parameter"
  exit 1
fi

echo ""
echo "Folders"
echo ${folders[@]}

echo ""
echo "System Tests"
echo ${systemTests[@]}


# Find directories starting with "performance" and iterate over them
for folder in "${folders[@]}"; do
  executeInEachFolder "$folder"
done