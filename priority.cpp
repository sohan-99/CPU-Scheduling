#include <bits/stdc++.h> // This line includes virtually all standard C++ headers in a single directive. It is essentially a shortcut to include every standard library header file, such as <iostream>, <vector>, <algorithm>, and many others.
using namespace std; // Allows the use of standard library names without the std:: prefix

struct Process // Defines a structure named Process
{
    int id; // An integer to store the process ID
    int burst_time; // An integer to store the burst time of the process
    int priority; // An integer to store the priority of the process
    int waiting_time; // An integer to store the waiting time of the process
};

int main() // The main function, the entry point of the program
{
    int n; // Declares an integer variable n to store the number of processes
    cout << "Enter the number of processes: "; // Prompts user to enter the number of processes
    cin >> n; // Reads the number of processes from user input

    vector<Process> processes(n); // Declares a vector of Process structures of size n

    cout << "Enter burst time and priority for each process:\n"; // Prompts user to enter burst time and priority for each process
    for (int i = 0; i < n; ++i) // Loops through each process
    {
        cout << "Process " << i + 1 << ":\n"; // Displays process number
        processes[i].id = i + 1; // Assigns process ID
        cout << "Burst Time: "; // Prompts user to enter burst time
        cin >> processes[i].burst_time; // Reads burst time for the current process
        cout << "Priority: "; // Prompts user to enter priority
        cin >> processes[i].priority; // Reads priority for the current process
    }

    // Sorts the processes based on their priority in ascending order
    sort(processes.begin(), processes.end(), [](const Process &a, const Process &b)
         { return a.priority < b.priority; });

    int total_waiting_time = 0; // Declares and initializes an integer to store the total waiting time
    processes[0].waiting_time = 0; // Initializes the waiting time of the first process to zero

    cout << "Process\tWaiting Time\n"; // Outputs table headers for process and waiting time
    for (int i = 1; i < n; ++i) // Loops through each process starting from the second one
    {
        // Calculates waiting time for the current process
        processes[i].waiting_time = processes[i - 1].waiting_time + processes[i - 1].burst_time;
        total_waiting_time += processes[i].waiting_time; // Adds current process waiting time to total waiting time
        cout << processes[i].id << "\t" << processes[i].waiting_time << endl; // Outputs process ID and waiting time
    }

    // Calculates the average waiting time
    double average_waiting_time = static_cast<double>(total_waiting_time) / n;
    cout << "Average Waiting Time: " << average_waiting_time << endl; // Outputs the average waiting time

    return 0; // Returns 0 to indicate successful execution
}
