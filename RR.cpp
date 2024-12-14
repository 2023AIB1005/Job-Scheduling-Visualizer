#include "RR.h"
#include <iostream>

// Constructor to initialize the Round Robin scheduler
abc_round_robin::abc_round_robin(int timeQuantum) : abc_timeQuantum(timeQuantum), abc_currentTime(0) {}

// Add a job to the job queue
void abc_round_robin::abc_addJob(const abc_job &job) {
    abc_jobQueue.push_back(job);
}

// The main scheduling function using Round Robin algorithm
std::vector<std::tuple<int, int, int>> abc_round_robin::abc_schedule() {
    std::cout << "Starting Round Robin Scheduling...\n";
    //create a new vector to store jobs with jobiD start time and end time 
    std::vector<std::tuple<int, int, int>> jobTime;
    
    while (!abc_jobQueue.empty()) {
        for (size_t i = 0; i < abc_jobQueue.size();) {
            abc_job &job = abc_jobQueue[i];
            std::cout << "Processing Job ID: " << job.abc_getJobID() << " at time " << abc_currentTime << "\n";
            
            // If the job can finish within the current time slice
            if (job.abc_getRemainingTime() <= abc_timeQuantum) {
                jobTime.push_back(std::make_tuple(job.abc_getJobID(), abc_currentTime, abc_currentTime + job.abc_getRemainingTime()));
                abc_currentTime += job.abc_getRemainingTime();
                std::cout << "Job ID: " << job.abc_getJobID() << " finished at time " << abc_currentTime << "\n";
                abc_jobQueue.erase(abc_jobQueue.begin() + i);  // Remove job from the queue
            } 
            // If the job requires more time than the time slice
            else {
                jobTime.push_back(std::make_tuple(job.abc_getJobID(), abc_currentTime, abc_currentTime + abc_timeQuantum));
                job.abc_setRemainingTime(job.abc_getRemainingTime() - abc_timeQuantum);
                abc_currentTime += abc_timeQuantum;
                std::cout << "Job ID: " << job.abc_getJobID() << " remaining time: " << job.abc_getRemainingTime() << "\n";
                i++;  // Move to the next job in the queue
            }
        }
    }
    return jobTime;
}

// Prints the job queue
void abc_round_robin::abc_printJobQueue() const {
    std::cout << "Job Queue:\n";
    for (const abc_job &job : abc_jobQueue) {
        std::cout << job.abc_toString() << ", Remaining Time: " << job.abc_getRemainingTime() << "\n";
    }
}
