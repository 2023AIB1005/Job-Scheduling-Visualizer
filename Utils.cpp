#include "Utils.h"
#include <iostream>
#include <iomanip>  // For formatting the output
#include <fstream>  // For file operations

// Function to calculate the average waiting time
double abc_calculateAverageWaitingTime(const std::vector<abc_job>& jobs) {
    double totalWaitingTime = 0.0;
    int n = jobs.size();
    
    for (const auto& job : jobs) {
        totalWaitingTime += job.abc_getWaitingTime();  // Assuming abc_getWaitingTime() is implemented in the job class
    }

    return n > 0 ? totalWaitingTime / n : 0.0; // Return 0 if there are no jobs
}

// Function to calculate the average turnaround time
double abc_calculateAverageTurnaroundTime(const std::vector<abc_job>& jobs) {
    double totalTurnaroundTime = 0.0;
    int n = jobs.size();
    
    for (const auto& job : jobs) {
        totalTurnaroundTime += job.abc_getTurnaroundTime();  // Assuming abc_getTurnaroundTime() is implemented in the job class
    }

    return n > 0 ? totalTurnaroundTime / n : 0.0; // Return 0 if there are no jobs
}

// Function to print the results of the scheduling
void abc_printResults(const std::vector<abc_job>& jobs) {
    std::cout << "Scheduling Results:\n";
    std::cout << "Job ID\tWaiting Time\tTurnaround Time\n";
    
    // Print details of each job
    for (const auto& job : jobs) {
        std::cout << job.abc_getJobID() << "\t"
                  << job.abc_getWaitingTime() << "\t\t"
                  << job.abc_getTurnaroundTime() << "\n";
    }

    // Calculate and print the averages
    std::cout << std::fixed << std::setprecision(2);  // Format the output to 2 decimal places
    std::cout << "Average Waiting Time: " << abc_calculateAverageWaitingTime(jobs) << "\n";
    std::cout << "Average Turnaround Time: " << abc_calculateAverageTurnaroundTime(jobs) << "\n";
}

void abc_createfile(const std::vector<std::tuple<int, int, int>>& jobTime, const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& job : jobTime) {
            file << std::get<0>(job) << "," << std::get<1>(job) << "," << std::get<2>(job) << "\n";
        }
        file.close();
        std::cout << "Results saved\n";
    } else {
        std::cerr << "Error: Unable to create file\n";
    }
}
