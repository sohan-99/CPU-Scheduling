#include <stdio.h>

int main()
{
    int n;
    printf("Enter how many processes: ");
    scanf("%d", &n);
    int burst_time[n], process[n];
    
    // Input burst time for each process
    for (int i = 0; i < n; i++)
    {
        printf("Enter burst time of p%d: ", i + 1);
        scanf("%d", &burst_time[i]);
        process[i] = i + 1;
    }

    // Sort processes based on burst time using Bubble Sort
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (burst_time[j] > burst_time[j + 1])
            {
                // Swap burst time
                int temp_burst = burst_time[j];
                burst_time[j] = burst_time[j + 1];
                burst_time[j + 1] = temp_burst;

                // Swap process
                int temp_process = process[j];
                process[j] = process[j + 1];
                process[j + 1] = temp_process;
            }
        }
    }

    int waiting_time = 0;
    printf("Process Waiting Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("p%d %d\n", process[i], waiting_time);
        waiting_time += burst_time[i];
    }
    return 0;
}
