#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Process
{
    int id;
    int burst_time;
    int priority;
    int waiting_time;
};

int main()
{
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> processes(n);

    cout << "Enter burst time and priority for each process:\n";
    for (int i = 0; i < n; ++i)
    {
        cout << "Process " << i + 1 << ":\n";
        processes[i].id = i + 1;
        cout << "Burst Time: ";
        cin >> processes[i].burst_time;
        cout << "Priority: ";
        cin >> processes[i].priority;
    }

    sort(processes.begin(), processes.end(), [](const Process &a, const Process &b)
         { return a.priority < b.priority; });

    int total_waiting_time = 0;
    processes[0].waiting_time = 0;

    cout << "Process\tWaiting Time\n";
    for (int i = 1; i < n; ++i)
    {
        processes[i].waiting_time = processes[i - 1].waiting_time + processes[i - 1].burst_time;
        total_waiting_time += processes[i].waiting_time;
        cout << processes[i].id << "\t" << processes[i].waiting_time << endl;
    }

    double average_waiting_time = static_cast<double>(total_waiting_time) / n;
    cout << "Average Waiting Time: " << average_waiting_time << endl;

    return 0;
}
