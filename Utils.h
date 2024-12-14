#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <vector>
#include "job.h"

// Function to calculate the average waiting time
double abc_calculateAverageWaitingTime(const std::vector<abc_job>& jobs);

// Function to calculate the average turnaround time
double abc_calculateAverageTurnaroundTime(const std::vector<abc_job>& jobs);

// Function to print the results of the scheduling
void abc_printResults(const std::vector<abc_job>& jobs);

void abc_createfile(const std::vector<std::tuple<int, int, int>>& jobTime, const std::string& filename);

#endif // UTILS_H
