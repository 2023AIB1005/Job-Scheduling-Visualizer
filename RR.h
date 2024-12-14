#ifndef RR_H
#define RR_H

#include <vector>
#include "job.h"

class abc_round_robin {
private:
    std::vector<abc_job> abc_jobQueue;  // List of jobs to be scheduled
    int abc_timeQuantum;                // Time slice for each job
    int abc_currentTime;                // Tracks the current time in the system

public:
    abc_round_robin(int timeQuantum);

    void abc_addJob(const abc_job &job);
    std::vector<std::tuple<int, int, int>> abc_schedule();                // Performs the scheduling
    void abc_printJobQueue() const;     // Prints the job queue for debugging
};

#endif // RR_H
