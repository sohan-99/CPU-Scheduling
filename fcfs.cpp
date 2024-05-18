#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter how many processes: ";
    cin >> n;
    int brust_time[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter brust time of p" << i + 1 << ": ";
        cin >> brust_time[i];
    }
    int waiting_time = 0;
    int total_waiting_time = 0;
    for (int i = 0; i < n; i++)
    {
        cout << "Waiting time of p" << i + 1 << ": " << waiting_time << endl;
        waiting_time += brust_time[i];
        total_waiting_time += waiting_time;
    }
    cout << "Average waiting time is: " << (total_waiting_time - waiting_time) / float(n) << endl;
    return 0;
}
