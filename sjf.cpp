#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Enter how many processes: ";
    cin >> n;
    int burst_time[n], process[n];

    // Input burst time for each process
    for (int i = 0; i < n; i++)
    {
        cout << "Enter burst time of p" << i + 1 << ": ";
        cin >> burst_time[i];
        process[i] = i + 1;
    }

    // Sort processes based on burst time
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (burst_time[i] < burst_time[j])
            {
                int temp = burst_time[i];
                burst_time[i] = burst_time[j];
                burst_time[j] = temp;

                // Process
                int temp_process = process[i];
                process[i] = process[j];
                process[j] = temp_process;
            }
        }
    }

    int waiting_time = 0;
    float total_waiting_time = 0;

    for (int i = 0; i < n; i++)
    {
        cout << "Waiting time of p" << process[i] << ": " << waiting_time << endl;
        total_waiting_time += waiting_time;
        waiting_time += burst_time[i];
    }

    float average_waiting_time = total_waiting_time / n;
    cout << "Average Waiting Time: " << average_waiting_time << endl;

    return 0;
}