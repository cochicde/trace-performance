"""
createImprovementsGraphs.py

This module provides functions for visualizing and comparing timing performance data using plots.
It leverages matplotlib and seaborn for plotting, and is designed to display mean execution times with standard deviation error bars for multiple datasets.
For each test, a line plot with all executtion time entries is generated.

It searches for CSV files in a specified directory to determine the executed tests. From the name of the file, it looks for a NAME.size file to determine the size of the trace in megabytes.
"""

import argparse
import glob
import matplotlib.pyplot as plt
import numpy as np
import os
import seaborn as sns

from common import ExecutedTest, read_and_process_file

def build_color_map(executed_tests, palette_name):
    """
    Assigns a fixed color to each test (by file_name) so that a given test is drawn with the same color in every plot, regardless of which other tests it is plotted alongside or in what order.
    """
    file_names = sorted({t.file_name for t in executed_tests})
    palette = sns.color_palette(palette_name, len(file_names))
    return {file_name: color for file_name, color in zip(file_names, palette)}

def plot_execution_time(executed_tests, labels, save_path, color_map):
    """
    Plots a bar chart comparing mean execution times and their standard deviations for multiple datasets.

    Each bar represents the mean execution time of a dataset, with error bars indicating the standard deviation.
    The chart is saved to the specified path and optionally displayed.

    Args:
      executed_tests (list): List of objects containing 'mean_time' and 'std_dev' attributes for each dataset.
      labels (list): List of strings representing the labels for each dataset/bar.
      save_path (str): File path to save the generated plot image.
      color_map (dict): Mapping of test file_name to a fixed color, so colors stay consistent across plots.

    Returns:
      None
    """
    fig, ax = plt.subplots(figsize=(14, 7))
    colors = [color_map[t.file_name] for t in executed_tests]
    x_positions = np.arange(len(labels))
    bars = ax.bar(
        x_positions,
        [t.mean_time for t in executed_tests],
        yerr=[t.std_dev for t in executed_tests],
        capsize=5, color=colors, edgecolor='black')

    ax.set_xticks(x_positions)
    ax.set_xticklabels(labels, rotation=30, ha="right", fontweight='bold')
    ax.tick_params(axis='both', which='major', labelsize=14)

    for bar, t in zip(bars, executed_tests):
        ax.text(bar.get_x() + bar.get_width()/2, bar.get_height() + t.std_dev + 5, f'{t.mean_time:.1f} ± {t.std_dev:.1f}',
                ha='center', va='bottom', fontsize=14, fontweight='bold', color='black')

    ax.set_ylabel("Time (microseconds)", fontsize=14)
    ax.set_title("", fontsize=16)
    ax.grid(axis='y', linestyle="--", alpha=0.7)
    ax.spines['top'].set_visible(False)
    ax.spines['right'].set_visible(False)

    plt.tight_layout()
    plt.savefig(save_path)
    plt.close()

def plot_trace_sizes(executed_tests, labels, save_path, color_map):
    """
    Plots a bar chart showing the size of traces for each executed test.

    Each bar represents the size of a trace in megabytes, with labels for each test.
    The chart is saved to the specified path.
    """
    trace_sizes = [t.trace_size_mb for t in executed_tests if t.trace_size_mb is not None]
    colors = [color_map[t.file_name] for t in executed_tests]

    fig, ax = plt.subplots(figsize=(14, 7))
    x_positions = np.arange(len(labels))
    bars = ax.bar(x_positions, trace_sizes, color=colors, edgecolor='black')

    ax.set_xticks(x_positions)
    ax.set_xticklabels(labels, rotation=30, ha="right", fontweight='bold')
    ax.tick_params(axis='both', which='major', labelsize=14)

    for bar, size in zip(bars, trace_sizes):
        ax.text(bar.get_x() + bar.get_width()/2, bar.get_height() + 2, f'{size:.1f} MB',
                ha='center', va='bottom', fontsize=12, fontweight='bold', color='black')

    ax.set_ylabel("Size of traces (MB)", fontsize=14)
    ax.set_title("", fontsize=16)
    ax.grid(axis='y', linestyle="--", alpha=0.7)
    ax.spines['top'].set_visible(False)
    ax.spines['right'].set_visible(False)

    plt.tight_layout()
    plt.savefig(save_path)
    plt.close()

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Visualize and compare timing performance data.")
    parser.add_argument("folder", nargs="?", default="./results/oneGeneratorOneConsumer_1x/", help="Directory containing CSV and size files (default: results/oneGeneratorOneConsumer_1x/)")
    args = parser.parse_args()
    directory = os.path.abspath(args.folder)

    # create executed tests from the csv files
    executed_tests = []
    file_paths = glob.glob(os.path.join(directory, "*.csv"))
    for file_path in file_paths:
        times = read_and_process_file(file_path)
        if not times:
            print(f"No valid time entries found in {file_path}.")
            continue
        
        # Determine the trace size from the corresponding .size file
        file_name = os.path.basename(file_path).replace(".csv", "")
        size_file_path = os.path.join(directory, f"{file_name}.size")

        if os.path.isfile(size_file_path):
            try:
                with open(size_file_path, 'r') as size_file:
                    trace_size_mb = float(size_file.read().strip())
            except ValueError:
                trace_size_mb = 0.0
        else:
            trace_size_mb = 0.0

        executed_test = ExecutedTest(file_name, times, os.path.dirname(directory), trace_size_mb)
        executed_test.plot(directory)
        executed_tests.append(executed_test)
            
    # Manually specify which groups of files to include in plots
    class TestToPlot:
      def __init__(self, file_name, label):
        self.file_name = file_name
        self.label = label

    class PlotImage:
      def __init__(self, tests):
        self.tests = tests

    plot_images = [
      PlotImage([TestToPlot("NotTraced", "Not Traced"), TestToPlot("Classic", "Existing traces")]),
      PlotImage([TestToPlot("Classic", "Existing traces"), TestToPlot("OnlySIFB", "Only SIFB outputs")]),
      PlotImage([TestToPlot("OnlySIFB", "Values as strings"), TestToPlot("Binary", "Values as binary")]),
      PlotImage([TestToPlot("Binary", "Values as binary"), TestToPlot("NoTypeOrClock", "Values without extra clock and type")]),
      PlotImage([TestToPlot("NoTypeOrClock", "Values without extra clock and type"), TestToPlot("Improvements", "Values with performance improvements")]),
      PlotImage([
        TestToPlot("Classic", "Existing traces"),
        TestToPlot("OnlySIFB", "Only SIFB outputs"),
        TestToPlot("Binary", "Values as binary"),
        TestToPlot("NoTypeOrClock", "No extra clock and type"),
        TestToPlot("Improvements", "Performance improvements"),
        TestToPlot("NotTraced", "Not Traced")
      ]),
      PlotImage([
        TestToPlot("OnlySIFB", "Only SIFB outputs"),
        TestToPlot("Binary", "Values as binary"),
        TestToPlot("NoTypeOrClock", "No extra clock and type"),
        TestToPlot("Improvements", "Performance improvements"),
        TestToPlot("NotTraced", "Not Traced")
      ]),
    ]
   
    time_color_map = build_color_map(executed_tests, "husl")
    size_color_map = build_color_map(executed_tests, "pastel")

    for image in plot_images:
      ordered_data = []
      labels = []
      for test in image.tests:
        # Find the matching ExecutedTest by file_name
        match = next((t for t in executed_tests if t.file_name == test.file_name), None)
        if match:
          ordered_data.append(match)
          labels.append(test.label)
      if ordered_data:
        base_filename = "vs".join([test.file_name for test in image.tests])
        time_plot_path = os.path.join(directory, base_filename + "_Time.png")
        size_plot_path = os.path.join(directory, base_filename + "_Size.png")

        plot_execution_time(ordered_data, labels, time_plot_path, time_color_map)
        plot_trace_sizes(ordered_data, labels, size_plot_path, size_color_map)