#include "FCFS.h"
#include <iostream>
#include <iomanip>

void abc_fcfs_scheduling::abc_addJob(const abc_job& job) {
    abc_jobQueue.push_back(job);
}

std::vector<std::tuple<int, int, int>> abc_fcfs_scheduling::abc_schedule() {
    int currentTime = 0;

    std::vector<std::tuple<int, int, int>> jobTime;

    for (auto& job : abc_jobQueue) {
        // Schedule job
        if (currentTime < job.abc_getArrivalTime()) {
            currentTime = job.abc_getArrivalTime(); // Wait until the job arrives
        }

        jobTime.push_back(std::make_tuple(job.abc_getJobID(), currentTime, currentTime + job.abc_getBurstTime()));
        // Update completion and turnaround times
        int completionTime = currentTime + job.abc_getBurstTime();
        job.abc_setTurnaroundTime(completionTime - job.abc_getArrivalTime());
        currentTime += job.abc_getBurstTime();
    }
    return jobTime;
}

void abc_fcfs_scheduling::abc_printJobQueue() {
    std::cout << "Scheduled Jobs:\n";
    for (const auto& job : abc_jobQueue) {
        std::cout << job.abc_toString() << std::endl;
    }
}

void abc_fcfs_scheduling::abc_printGanttChart() {
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
