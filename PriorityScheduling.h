#ifndef PRIORITYSCHEDULING_H
#define PRIORITYSCHEDULING_H

#include <vector>
#include "job.h"

class abc_priority_scheduling {
private:
    std::vector<abc_job> abc_jobQueue;  // List of jobs to be scheduled
    int abc_currentTime;                // Tracks the current time in the system

public:
    abc_priority_scheduling();

    void abc_addJob(const abc_job &job);
    std::vector<std::tuple<int, int, int>> abc_schedule();                // Performs the scheduling based on priority
    void abc_printJobQueue() const;    // Prints the job queue for debugging
    void abc_printGanttChart();

};

#endif // PRIORITYSCHEDULING_H
