#include "PriorityScheduling.h"
#include <iostream>
#include <algorithm>

// Constructor to initialize the Priority Scheduling
abc_priority_scheduling::abc_priority_scheduling() : abc_currentTime(0) {}

// Add a job to the job queue
void abc_priority_scheduling::abc_addJob(const abc_job &job) {
    abc_jobQueue.push_back(job);
}

// The main scheduling function using Priority Scheduling algorithm
std::vector<std::tuple<int, int, int>> abc_priority_scheduling::abc_schedule() {
    std::cout << "Starting Priority Scheduling...\n";

    // Sort the job queue based on job priority (higher priority value means higher priority)
    std::sort(abc_jobQueue.begin(), abc_jobQueue.end(), [](const abc_job &a, const abc_job &b) {
        return a.abc_getPriority() > b.abc_getPriority();  // Sort by descending priority
    });

    //create a new vector to store jobs with jobiD start time and end time 
    std::vector<std::tuple<int, int, int>> jobTime;

    // Process each job in the order of priority
    for (const abc_job &job : abc_jobQueue) {
        std::cout << "Processing Job ID: " << job.abc_getJobID() 
                  << " with Priority: " << job.abc_getPriority() 
                  << " at time " << abc_currentTime << "\n";
                  //store jobid and start time in the vector 
        jobTime.push_back(std::make_tuple(job.abc_getJobID(), abc_currentTime, abc_currentTime + job.abc_getBurstTime()));

        abc_currentTime += job.abc_getBurstTime();  // Simulate processing the job
        std::cout << "Job ID: " << job.abc_getJobID() << " finished at time " << abc_currentTime << "\n";
    }

    // Clear the job queue after scheduling
    abc_jobQueue.clear();

    return jobTime;
}

// Prints the job queue
void abc_priority_scheduling::abc_printJobQueue() const {
    std::cout << "Job Queue:\n";
    for (const abc_job &job : abc_jobQueue) {
        std::cout << job.abc_toString() << ", Priority: " << job.abc_getPriority() << "\n";
    }
}
