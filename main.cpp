#include <iostream>
#include <vector>
#include "FCFS.h"
#include "SJF.h"
#include "PriorityScheduling.h"
#include "job.h"
#include "Utils.h"
#include "RR.h"

int main() {
    int numJobs;
    std::cout << "Enter the number of jobs: ";  // Prompt for the number of jobs
    std::cin >> numJobs;

    std::vector<abc_job> jobs;
    
    // Input job details dynamically
    for (int i = 0; i < numJobs; ++i) {
        int jobID, arrivalTime, burstTime, priority;

        // Instructions for user input
        std::cout << "Enter details for Job " << (i + 1) 
                  << " (ID ArrivalTime BurstTime Priority):\n"
                  << "Format: <Job ID> <Arrival Time> <Burst Time> <Priority>\n";

        // Read job details
        std::cin >> jobID >> arrivalTime >> burstTime >> priority;

        // Create job object and add to the jobs vector
        jobs.emplace_back(jobID, arrivalTime, burstTime, priority);
    }

    // User chooses the scheduling algorithm
    int algorithmChoice;
    std::cout << "\nChoose Scheduling Algorithm:\n";
    std::cout << "1. First Come First Serve (FCFS)\n";
    std::cout << "2. Shortest Job First (SJF)\n";
    std::cout << "3. Priority Scheduling\n";
    std::cout << "4. Round RObin Scheduling\n";
    std::cout << "Enter your choice (1-4): ";
    std::cin >> algorithmChoice;

    // Initialize the scheduling algorithm
    if (algorithmChoice == 1) {
        abc_fcfs_scheduling fcfsScheduler;

        // Add jobs to FCFS scheduler
        for (const auto& job : jobs) {
            fcfsScheduler.abc_addJob(job);
        }

        // Schedule jobs using FCFS
        std::cout << "\nFirst Come First Serve Scheduling:\n";
        std::vector<std::tuple<int, int, int>> gantt =  fcfsScheduler.abc_schedule();
        abc_createfile(gantt, "FCFSSchedulingResults.csv");
        fcfsScheduler.abc_printJobQueue();
        fcfsScheduler.abc_printGanttChart(); // Print Gantt Chart for FCFS

    } else if (algorithmChoice == 2) {
        abc_sjf_scheduling sjfScheduler;

        // Add jobs to SJF scheduler
        for (const auto& job : jobs) {
            sjfScheduler.abc_addJob(job);
        }

        // Schedule jobs using SJF
        std::cout << "\nShortest Job First Scheduling:\n";
        std::vector<std::tuple<int, int, int>> gantt = sjfScheduler.abc_schedule();
        abc_createfile(gantt, "SJFSchedulingResults.csv");
        sjfScheduler.abc_printJobQueue();
        sjfScheduler.abc_printGanttChart(); // Print Gantt Chart for SJF

    } else if (algorithmChoice == 3) {
        abc_priority_scheduling priorityScheduler;

        // Add jobs to Priority scheduler
        for (const auto& job : jobs) {
            priorityScheduler.abc_addJob(job);
        }

        // Schedule jobs using Priority Scheduling
        std::cout << "\nPriority Scheduling:\n";
        std::vector<std::tuple<int, int, int>> gantt = priorityScheduler.abc_schedule();
        abc_createfile(gantt, "PrioritySchedulingResults.csv");
        priorityScheduler.abc_printJobQueue();

    } else if (algorithmChoice ==4){
        std::cout << "Enter time quantum:\n";
        int timQuant;
        std::cin >> timQuant;
        abc_round_robin roundRobinScheduler(timQuant);

        for (const auto& job : jobs) {
            roundRobinScheduler.abc_addJob(job);
        }

        // Schedule jobs using Round Robin
        std::cout << "\nRound Robin Scheduling:\n";
        std::vector<std::tuple<int, int, int>> gantt = roundRobinScheduler.abc_schedule();  // Call the schedule method
        abc_createfile(gantt, "RRSchedulingResults.csv");

        //roundRobinScheduler.abc_printJobQueue(); for debugging

    } 
    
    else {
        std::cout << "Invalid choice. Please select a valid algorithm." << std::endl;
    }

    return 0;
}
