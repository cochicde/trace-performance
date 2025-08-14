
import re
import numpy as np
import matplotlib.pyplot as plt
import os

class ExecutedTest:
    """
    Represents the results of an executed test, including timing and optional trace size.

    Args:
      file_name (str): Name of the CSV file containing execution time entries.
      time_values (list or np.ndarray): List of execution time entries (in microseconds).
      folder_name (str): Name of the folder containing the test results.
      trace_size_mb (float, optional): Size of the trace file in megabytes.

    Attributes:
      file_name (str): Name of the CSV file with execution time entries.
      folder_name (str): Name of the folder containing the test results.
      short_name (str): Shortened folder name for display.
      time_values (list or np.ndarray): List of execution time entries (in microseconds).
      mean_time (float): Mean value of the execution time entries.
      std_dev (float): Standard deviation of the execution time entries.
      trace_size_mb (float, optional): Size of the trace file in megabytes.
    """

    def __init__(self, file_name, time_values, folder_name, trace_size_mb=None):
        self.file_name = file_name
        self.folder_name = folder_name
        self.short_name = folder_name.split('_', 1)[1] if '_' in folder_name else folder_name
        self.time_values = time_values
        self.mean_time = np.mean(time_values)
        self.std_dev = np.std(time_values)
        self.trace_size_mb = trace_size_mb

    def plot(self, directory):
        """
          Plots all time execution entries and saves the plot as a PNG file in the specified directory.
          The plot displays each entry's execution time, with labeled axes and grid for clarity.
        """
        plot_path = os.path.join(directory, f"{self.file_name}_detailed.png")
        plt.figure(figsize=(12, 6))
        plt.plot(self.time_values, marker='o', linestyle='-')

        # Removed text annotations and title

        plt.xlabel("Entry Number", fontsize=14)
        plt.ylabel("Time (microseconds)", fontsize=14)
        plt.xticks(fontsize=14)
        plt.yticks(fontsize=14)
        plt.grid()
        plt.tight_layout()
        plt.savefig(plot_path)
        plt.close()

def parse_time_to_microseconds(time_str):
    """
    Parses a time string with the format 'XXXmsYYYusZZZns' and converts it to microseconds.
    """
    units = {"ns": 0.001, "us": 1, "ms": 1000}  # Conversion to microseconds
    time_pattern = re.findall(r"(\d+)(ns|us|ms)", time_str)
    total_microseconds = sum(int(value) * units[unit] for value, unit in time_pattern)
    return total_microseconds

def read_and_process_file(file_path):
    """
    Reads a file with entries in the format 'T#XXXmsYYYusZZZns;' and extracts the time values in microseconds.
    """
    time_values = []
    with open(file_path, 'r') as file:
        for line in file:
            match = re.search(r"T#(.*?);", line)
            if match:
                time_str = match.group(1)
                time_values.append(parse_time_to_microseconds(time_str))
    return time_values