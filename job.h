#ifndef JOB_H
#define JOB_H

#include <string>

class abc_job {
private:
    int abc_jobID;
    int abc_arrivalTime;
    int abc_burstTime;
    int abc_priority; // for Priority Scheduling
    int abc_remainingTime; // for Round Robin Scheduling
    int abc_turnaroundTime; // Turnaround time
    int abc_completionTime; // Completion time

public:
    abc_job(int jobID, int arrivalTime, int burstTime, int priority = 0);

    // Getters
    int abc_getJobID() const;
    int abc_getArrivalTime() const;
    int abc_getBurstTime() const;
    int abc_getPriority() const;
    int abc_getRemainingTime() const;
    int abc_getTurnaroundTime() const;
    int abc_getCompletionTime() const;

    // Setters
    void abc_setRemainingTime(int time);
    void abc_setTurnaroundTime(int time);
    void abc_setCompletionTime(int time);

    int abc_getWaitingTime() const;

    // Utility methods
    std::string abc_toString() const;
};

#endif // JOB_H
