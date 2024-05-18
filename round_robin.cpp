#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    int count, n, time, remain, flag = 0, time_quantum;
    int wait_time = 0, turnaround_time = 0, bt[10], rt[10];
    cout << "Enter Total Process:\t ";
    cin >> n;
    remain = n;
    for (count = 0; count < n; count++)
    {
        cout << "Enter Burst Time for Process Number " << count + 1 << ": ";
        cin >> bt[count];
        rt[count] = bt[count];
    }
    cout << "Enter Time Quantum:\t";
    cin >> time_quantum;
    cout << "\n\nProcess\t| Turnaround Time | Waiting Time\n\n";
    for (time = 0, count = 0; remain != 0;)
    {
        if (rt[count] <= time_quantum && rt[count] > 0)
        {
            time += rt[count];
            rt[count] = 0;
            flag = 1;
        }
        else if (rt[count] > 0)
        {
            rt[count] -= time_quantum;
            time += time_quantum;
        }
        if (rt[count] == 0 && flag == 1)
        {
            remain--;
            cout << "P[" << count + 1 << "]\t|\t" << time << "\t|\t" << time - bt[count] << "\n";
            wait_time += time - bt[count];
            turnaround_time += time;
            flag = 0;
        }
        if (count == n - 1)
            count = 0;
        else
            count++;
    }
    cout << "\nAverage Waiting Time = " << (float)wait_time / n;
    cout << "\nAverage Turnaround Time = " << (float)turnaround_time / n;
    return 0;
}
