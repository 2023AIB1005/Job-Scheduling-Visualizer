# Compiler
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

# Source files
SRCS = main.cpp job.cpp Utils.cpp FCFS.cpp SJF.cpp RR.cpp PriorityScheduling.cpp 

# Header files (optional, but good for clarity)
HEADERS = job.h Utils.h FCFS.h SJF.h RR.h PriorityScheduling.h 

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable name
EXEC = JobSchedulingVisualizer

# Default target
all: $(EXEC)

# Link object files to create the executable
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile each source file into an object file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up generated files
clean:
	rm -f $(OBJS) $(EXEC) *.csv

# Run the program
run: $(EXEC)
	./$(EXEC)

.PHONY: all clean run
