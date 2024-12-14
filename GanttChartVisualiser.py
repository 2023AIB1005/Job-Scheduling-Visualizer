import matplotlib.pyplot as plt
import pandas as pd
import glob
import os
import mplcursors

def gantt_chart_visualiser(filename):
    # Read data from the file
    data = pd.read_csv(filename, names=["JobID", "Start", "End"])

    # Determine the scheduling type
    basename = os.path.basename(filename)
    p_basename = "Unknown Scheduling"
    if basename == "FCFSSchedulingResults.csv":
        p_basename = "FCFS Scheduling"
    elif basename == "PrioritySchedulingResults.csv":
        p_basename = "Priority Scheduling"
    elif basename == "SJFSchedulingResults.csv":
        p_basename = "SJF Scheduling"
    elif basename == "RRSchedulingResults.csv":
        p_basename = "RR Scheduling"

    # Calculate metrics
    total_time = max(data["End"]) - min(data["Start"])
    total_exec_time = sum(data["End"] - data["Start"])
    cpu_utilization = (total_exec_time / total_time) * 100
    wait_times = data["Start"] - min(data["Start"])
    avg_wait_time = wait_times.mean()
    turnaround_times = data["End"] - data["Start"]
    avg_turnaround_time = turnaround_times.mean()

    # Plot Gantt Chart
    fig, ax = plt.subplots()
    for idx, row in data.iterrows():
        ax.broken_barh([(row["Start"], row["End"] - row["Start"])], (10 * idx, 9), facecolors='blue')
        ax.text((row["Start"] + row["End"]) / 2, 10 * idx + 5, row["JobID"], color='white', fontweight='bold')

    # Set labels and title
    ax.set_xlabel('Time')
    ax.set_yticks([10 * idx + 5 for idx in range(len(data))])
    ax.set_yticklabels(data["JobID"])
    ax.set_title(f'Gantt Chart for {p_basename}')

    # Display metrics as a table on the plot
    metrics_data = [
        ["CPU Utilization (%)", f"{cpu_utilization:.2f}"],
        ["Average Wait Time", f"{avg_wait_time:.2f}"],
        ["Average Turnaround Time", f"{avg_turnaround_time:.2f}"]
    ]
    table = ax.table(cellText=metrics_data, colLabels=["Metric", "Value"], cellLoc='center', loc='right')
    table.auto_set_font_size(False)
    table.set_fontsize(10)
    table.scale(1, 1.5)  # Adjust the scale if needed

    # Add tooltips
    cursor = mplcursors.cursor(ax, hover=True)
    cursor.connect(
        "add", lambda sel: sel.annotation.set_text(
            f"Job ID: {data.iloc[sel.index]['JobID']}\n"
            f"Start: {data.iloc[sel.index]['Start']}\n"
            f"End: {data.iloc[sel.index]['End']}\n"
            f"Duration: {data.iloc[sel.index]['End'] - data.iloc[sel.index]['Start']}"
        )
    )

    # Show the plot
    plt.show()

# Directory containing the CSV files
csv_folder = "/Users/tanishka/Desktop/DSA Project"  # Replace with your CSV folder path

# Loop through each CSV file and visualize
for csv_file in glob.glob(os.path.join(csv_folder, "*.csv")):
    print(f"Visualizing Gantt chart for: {csv_file}")
    gantt_chart_visualiser(csv_file)
