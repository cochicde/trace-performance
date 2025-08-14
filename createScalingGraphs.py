import argparse
import matplotlib.pyplot as plt
import os

from common import ExecutedTest, read_and_process_file

def plot_line_graph(data_by_file, prefix, time_unit, log_base, output_dir):
    plt.figure(figsize=(12, 6))

    if time_unit == "ms":
        conversion_factor = 1000
        ylabel = "Mean Time (milliseconds)"
    else:
        conversion_factor = 1
        ylabel = "Mean Time (microseconds)"

    for file_key in data_by_file:
        sorted_data = sorted(data_by_file[file_key], key=lambda d: len(d.short_name))
        x_labels = [d.short_name for d in sorted_data]
        mean_times = [d.mean_time / conversion_factor for d in sorted_data]

        plt.plot(x_labels, mean_times, marker='o', linestyle='-', linewidth=2, label=file_key)

        for i, value in enumerate(mean_times):
            plt.text(i, value, f'{value:.1f}', ha='center', va='bottom', fontsize=10, color='black')

    plt.ylabel(ylabel)
    plt.xlabel("Percentage of SIFBs")
    plt.yscale('log' if log_base == 'log' else 'log', base=2 if log_base == 'log2' else 10)
    plt.xticks(rotation=45, ha='right')
    plt.grid(True, linestyle='--', alpha=0.6)
    plt.legend()
    plt.tick_params(axis='y', labelsize=12)
    plt.subplots_adjust(left=0.1, right=0.95, top=0.95, bottom=0.25)
    save_path = os.path.join(output_dir, f"{prefix}_line_graph.png")
    plt.savefig(save_path, bbox_inches='tight')
    plt.close()

def plot_trace_sizes(data_by_file, prefix, log_base, output_dir):
    plt.figure(figsize=(12, 6))
    for file_key in data_by_file:
        sorted_data = sorted(data_by_file[file_key], key=lambda d: len(d.short_name))
        x_labels = [d.short_name for d in sorted_data if d.trace_size_mb > 0]
        sizes_mb = [d.trace_size_mb for d in sorted_data if d.trace_size_mb > 0]

        if sizes_mb:
            plt.plot(x_labels, sizes_mb, marker='s', linestyle='--', linewidth=2, label=file_key)

            for i, value in enumerate(sizes_mb):
                plt.text(i, value, f'{value:.1f}', ha='center', va='bottom', fontsize=10, color='black')

    plt.xlabel("Percentage of SIFBs")
    plt.ylabel("Trace Size (MB)")
    plt.yscale('log' if log_base == 'log' else 'log', base=2 if log_base == 'log2' else 10)
    plt.xticks(rotation=45, ha='right')
    plt.grid(True, linestyle='--', alpha=0.6)
    plt.legend()
    plt.tick_params(axis='y', labelsize=12)
    plt.subplots_adjust(left=0.1, right=0.95, top=0.95, bottom=0.25)
    save_path = os.path.join(output_dir, f"{prefix}_trace_size_graph.png")
    plt.savefig(save_path, bbox_inches='tight')
    plt.close()

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Visualize and compare timing performance data.")
    parser.add_argument("folder", nargs="?", default="./results/", help="Parent directory of the results and where the images are saved (default: results/")
    args = parser.parse_args()

    base_directory = os.path.abspath(args.folder)
    output_directory = base_directory

    plot_configs = [
        {
          "title": "IncreaasinAmountOfFBs",
          "time_unit": "us",
          "log_base": "log10",
          "lines": [
              {
                "label": "Traced",
                "inputs": [
                        {"folder": "oneGeneratorOneConsumer_1x", "file": "Improvements"},
                        {"folder": "oneGeneratorOneConsumer_10x", "file": "Improvements"},
                        {"folder": "oneGeneratorOneConsumer_100x", "file": "Improvements"}
                    ]
              },
              {
                "label": "Not Traced",
                "inputs": [
                        {"folder": "oneGeneratorOneConsumer_1x", "file": "NotTraced"},
                        {"folder": "oneGeneratorOneConsumer_10x", "file": "NotTraced"},
                        {"folder": "oneGeneratorOneConsumer_100x", "file": "NotTraced"},
                    ]
              }
          ]
        },
        {
          "title": "ScalingSIFBs",
          "time_unit": "us",
          "log_base": "log2",
          "lines": [
              {
                "label": "Traced",
                "inputs": [
                        {"folder": "SIFB_3", "file": "Improvements"},
                        {"folder": "SIFB_6", "file": "Improvements"},
                        {"folder": "SIFB_12", "file": "Improvements"},
                        {"folder": "SIFB_25", "file": "Improvements"},
                        {"folder": "SIFB_50", "file": "Improvements"},
                        {"folder": "SIFB_100", "file": "Improvements"},
                    ]
              },
              {
                "label": "Not Traced",
                "inputs": [
                        {"folder": "SIFB_3", "file": "NotTraced"},
                        {"folder": "SIFB_6", "file": "NotTraced"},
                        {"folder": "SIFB_12", "file": "NotTraced"},
                        {"folder": "SIFB_25", "file": "NotTraced"},
                        {"folder": "SIFB_50", "file": "NotTraced"},
                        {"folder": "SIFB_100", "file": "NotTraced"},
                    ]
              }
          ]
        },
        {
          "title": "ScalingHeavierSIFBs",
          "time_unit": "us",
          "log_base": "log2",
          "lines": [
              {
                "label": "Traced",
                "inputs": [
                        {"folder": "ManyOutputsSIFB_3", "file": "Improvements"},
                        {"folder": "ManyOutputsSIFB_6", "file": "Improvements"},
                        {"folder": "ManyOutputsSIFB_12", "file": "Improvements"},
                        {"folder": "ManyOutputsSIFB_25", "file": "Improvements"},
                        {"folder": "ManyOutputsSIFB_50", "file": "Improvements"},
                        {"folder": "ManyOutputsSIFB_100", "file": "Improvements"},
                    ]
              },
              {
                "label": "Not Traced",
                "inputs": [
                        {"folder": "ManyOutputsSIFB_3", "file": "NotTraced"},
                        {"folder": "ManyOutputsSIFB_6", "file": "NotTraced"},
                        {"folder": "ManyOutputsSIFB_12", "file": "NotTraced"},
                        {"folder": "ManyOutputsSIFB_25", "file": "NotTraced"},
                        {"folder": "ManyOutputsSIFB_50", "file": "NotTraced"},
                        {"folder": "ManyOutputsSIFB_100", "file": "NotTraced"},
                    ]
              }
          ]
        }
    ]

    for config in plot_configs:
        title = config["title"]
        time_unit = config["time_unit"]
        log_base = config["log_base"]
        data_by_file = {}

        for line in config["lines"]:
            label = line["label"]
            for entry in line["inputs"]:
                folder_path = os.path.join(base_directory, entry["folder"])
                file_path = os.path.join(folder_path, f"{entry['file']}.csv")
                if not os.path.isfile(file_path):
                    continue

                time_values = read_and_process_file(file_path)
                if not time_values:
                    continue

                size_file_path = os.path.join(folder_path, f"{entry['file']}.size")
                if os.path.isfile(size_file_path):
                    try:
                        with open(size_file_path, 'r') as size_file:
                            trace_size_mb = float(size_file.read().strip())
                    except ValueError:
                        trace_size_mb = 0.0
                else:
                    trace_size_mb = 0.0

                timing_data = ExecutedTest(entry['file'], time_values, entry['folder'], trace_size_mb)
                if label not in data_by_file:
                    data_by_file[label] = []
                data_by_file[label].append(timing_data)

        plot_line_graph(data_by_file, title, time_unit, log_base, output_directory)
        plot_trace_sizes(data_by_file, title, log_base, output_directory)
