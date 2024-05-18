#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, time = 0, remain, time_quantum;
    cout << "Enter Total Number of Processes: ";
    cin >> n;
    remain = n;
    vector<int> bt(n), rt(n);

    for (int i = 0; i < n; ++i)
    {
        cout << "Enter Burst Time for Process " << i + 1 << ": ";
        cin >> bt[i];
        rt[i] = bt[i];
    }

    cout << "Enter Time Quantum: ";
    cin >> time_quantum;
    cout << "\nProcess | Turnaround Time | Waiting Time\n\n";

    int wait_time = 0, turnaround_time = 0;
    for (int i = 0; remain != 0;)
    {
        if (rt[i] > 0)
        {
            if (rt[i] <= time_quantum)
            {
                time += rt[i];
                rt[i] = 0;
                remain--;
                int turnaround = time;
                int waiting = time - bt[i];
                cout << "P[" << i + 1 << "]    | " << turnaround << "              | " << waiting << "\n";
                wait_time += waiting;
                turnaround_time += turnaround;
            }
            else
            {
                rt[i] -= time_quantum;
                time += time_quantum;
            }
        }
        i = (i + 1) % n;
    }

    cout << "\nAverage Waiting Time = " << (float)wait_time / n;
    cout << "\nAverage Turnaround Time = " << (float)turnaround_time / n;
    return 0;
}