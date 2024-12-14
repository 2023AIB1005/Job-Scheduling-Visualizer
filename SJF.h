#ifndef SJF_H
#define SJF_H

#include <vector>
#include "job.h"

class abc_sjf_scheduling {
private:
    std::vector<abc_job> abc_jobQueue;  // List of jobs to be scheduled
    int abc_currentTime;                // Tracks the current time in the system

public:
    abc_sjf_scheduling();

    void abc_addJob(const abc_job &job);
    std::vector<std::tuple<int, int, int>> abc_schedule();                // Performs the scheduling based on SJF algorithm
    void abc_printJobQueue() const;     // Prints the job queue for debugging
    void abc_printGanttChart();         // Print Gantt chart for scheduled jobs
};

#endif // SJF_H
