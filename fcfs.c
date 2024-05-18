#include <stdio.h>

int main()
{
    int n;
    printf("Enter how many processes :");
    scanf("%d", &n);
    int brust_time[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter brust time of p%d:", i + 1);
        scanf("%d", &brust_time[i]);
    }
    int waiting_time = 0;
    int total_waiting_time = 0;
    for (int i = 0; i < n; i++)
    {
        printf("Waiting time of p%d:%d\n", i + 1, waiting_time);
        waiting_time += brust_time[i];
        total_waiting_time += waiting_time;
    }
    float avg = (total_waiting_time - waiting_time) / (float)n;
    printf("Average waiting time : %.2f\n", avg);
    return 0;
}