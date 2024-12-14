#include "SJF.h"
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;


// Constructor to initialize the SJF scheduler
abc_sjf_scheduling::abc_sjf_scheduling() : abc_currentTime(0) {}

// Add a job to the job queue
void abc_sjf_scheduling::abc_addJob(const abc_job &job) {
    abc_jobQueue.push_back(job);
}

// The main scheduling function using SJF algorithm
std::vector<std::tuple<int, int, int>> abc_sjf_scheduling::abc_schedule() {
    std::cout << "Starting Shortest Job First Scheduling...\n";

    // Sort the job queue based on burst time (shortest job first)
    std::sort(abc_jobQueue.begin(), abc_jobQueue.end(), [](const abc_job &a, const abc_job &b) {
        return a.abc_getBurstTime() < b.abc_getBurstTime();  // Sort by ascending burst time
    });

    std::vector<std::tuple<int, int, int>> jobTime;

    // Process each job in the order of shortest job first
    for ( abc_job &job : abc_jobQueue) {
        std::cout << "Processing Job ID: " << job.abc_getJobID()
                  << " with Burst Time: " << job.abc_getBurstTime()
                  << " at time " << abc_currentTime << "\n";


        jobTime.push_back(std::make_tuple(job.abc_getJobID(), abc_currentTime, abc_currentTime + job.abc_getBurstTime()));
        // Update current time
        abc_currentTime += job.abc_getBurstTime();  // Simulate processing the job

        // Calculate turnaround time and set it
        job.abc_setTurnaroundTime(abc_currentTime - job.abc_getArrivalTime());
        std::cout << "Job ID: " << job.abc_getJobID() << " finished at time " << abc_currentTime << "\n";
    }

    // Print Gantt chart after scheduling
    abc_printGanttChart();

    // Clear the job queue after scheduling
    abc_jobQueue.clear();
    return jobTime;
}

// Prints the job queue
void abc_sjf_scheduling::abc_printJobQueue() const {
    std::cout << "Job Queue:\n";
    for (const abc_job &job : abc_jobQueue) {
        std::cout << job.abc_toString() << ", Burst Time: " << job.abc_getBurstTime() << "\n";
    }
}

// Print Gantt Chart
void abc_sjf_scheduling::abc_printGanttChart() {
    std::cout << "Gantt Chart:\n";
    std::cout << "|";

    // Print job IDs in the Gantt chart
    for (const auto& job : abc_jobQueue) {
        std::cout << " Job " << job.abc_getJobID() << " |";
    }
    std::cout << std::endl;

    // Print time labels
    int currentTime = 0;
    std::cout << currentTime; // Initial time
    for (const auto& job : abc_jobQueue) {
        currentTime += job.abc_getBurstTime();
        std::cout << std::setw(9) << currentTime; // Print the end time of each job
    }
    std::cout << std::endl;
}
