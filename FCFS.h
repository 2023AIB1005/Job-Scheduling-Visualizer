#ifndef FCFS_H
#define FCFS_H

#include <vector>
#include "job.h"

class abc_fcfs_scheduling {
private:
    std::vector<abc_job> abc_jobQueue;

public:
    void abc_addJob(const abc_job& job);
    std::vector<std::tuple<int, int, int>> abc_schedule();
    void abc_printJobQueue();
    void abc_printGanttChart(); // New function to print Gantt chart
};

#endif // FCFS_H
