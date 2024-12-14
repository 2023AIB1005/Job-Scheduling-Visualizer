#include "job.h"

// Constructor
abc_job::abc_job(int jobID, int arrivalTime, int burstTime, int priority)
    : abc_jobID(jobID), abc_arrivalTime(arrivalTime), abc_burstTime(burstTime),
      abc_priority(priority), abc_remainingTime(burstTime), abc_turnaroundTime(0) {}

// Getters
int abc_job::abc_getJobID() const { return abc_jobID; }
int abc_job::abc_getArrivalTime() const { return abc_arrivalTime; }
int abc_job::abc_getBurstTime() const { return abc_burstTime; }
int abc_job::abc_getPriority() const { return abc_priority; }
int abc_job::abc_getRemainingTime() const { return abc_remainingTime; }
int abc_job::abc_getTurnaroundTime() const { return abc_turnaroundTime; } // Getter implementation

// Setters
void abc_job::abc_setRemainingTime(int time) { abc_remainingTime = time; }
void abc_job::abc_setTurnaroundTime(int time) { abc_turnaroundTime = time; } // Setter implementation

int abc_job::abc_getWaitingTime() const {
    return abc_turnaroundTime - abc_burstTime;
}
// Utility methods
std::string abc_job::abc_toString() const {
    return "Job ID: " + std::to_string(abc_jobID) +
           ", Arrival Time: " + std::to_string(abc_arrivalTime) +
           ", Burst Time: " + std::to_string(abc_burstTime) +
           ", Priority: " + std::to_string(abc_priority);
}
