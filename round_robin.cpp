#include <bits/stdc++.h> // This line includes virtually all standard C++ headers in a single directive. It is essentially a shortcut to include every standard library header file, such as <iostream>, <vector>, <algorithm>, and many others.
using namespace std; // Allows the use of standard library names without the std:: prefix

int main() // The main function, the entry point of the program
{
    int n, time = 0, remain, time_quantum; // Declares integer variables: n for number of processes, time for current time, remain for remaining processes, and time_quantum for the time slice
    cout << "Enter Total Number of Processes: "; // Prompts user to enter the number of processes
    cin >> n; // Reads the number of processes from user input
    remain = n; // Initializes the remaining processes count to n
    vector<int> bt(n), rt(n); // Declares two vectors of size n: bt for burst times and rt for remaining times

    for (int i = 0; i < n; ++i) // Loops through each process
    {
        cout << "Enter Burst Time for Process " << i + 1 << ": "; // Prompts user to enter the burst time for each process
        cin >> bt[i]; // Reads the burst time for the current process
        rt[i] = bt[i]; // Initializes the remaining time for each process to its burst time
    }

    cout << "Enter Time Quantum: "; // Prompts user to enter the time quantum
    cin >> time_quantum; // Reads the time quantum from user input

    int wait_time = 0, turnaround_time = 0; // Initializes wait time and turnaround time to zero
    for (int i = 0; remain != 0;) // Loops until there are no remaining processes
    {
        if (rt[i] > 0) // Checks if the current process has remaining time
        {
            if (rt[i] <= time_quantum) // If remaining time is less than or equal to time quantum
            {
                time += rt[i]; // Increment current time by remaining time
                rt[i] = 0; // Set remaining time to zero as process is completed
                remain--; // Decrement the remaining processes count
                int turnaround = time; // Calculate turnaround time for the current process
                int waiting = time - bt[i]; // Calculate waiting time for the current process
                wait_time += waiting; // Accumulate waiting time
                turnaround_time += turnaround; // Accumulate turnaround time
            }
            else // If remaining time is greater than time quantum
            {
                rt[i] -= time_quantum; // Decrease remaining time by time quantum
                time += time_quantum; // Increment current time by time quantum
            }
        }
        i = (i + 1) % n; // Move to the next process (circularly)
    }

    cout << "\nAverage Waiting Time = " << (float)wait_time / n; // Calculate and display the average waiting time

    return 0; // Return 0 to indicate successful execution
}
