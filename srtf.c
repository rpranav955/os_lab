#include <stdio.h>
#include <limits.h>

int main()
{
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int arrival[n], burst[n], remaining[n], finish[n], wt[n], tat[n];

    for (int i = 0; i < n; i++)
    {
        printf("P%d Arrival: ", i + 1);
        scanf("%d", &arrival[i]);
        printf("P%d Burst: ", i + 1);
        scanf("%d", &burst[i]);
        remaining[i] = burst[i];
    }

    int time = 0, completed = 0, prev = -1;
    printf("\nGantt Chart:\n");

    while (completed < n)
    {
        int index = -1, min = 9999;
        for (int i = 0; i < n; i++)
        {
            if (arrival[i] <= time && remaining[i] > 0 && remaining[i] < min)
            {
                min = remaining[i];
                index = i;
            }
        }

        if (index == -1)
        {
            time++;
            continue;
        }

        if (index != prev)
        {
            printf("%d(P%d) ", time, index + 1);
            prev = index;
        }

        remaining[index]--;
        time++;

        if (remaining[index] == 0)
        {
            finish[index] = time;
            tat[index] = finish[index] - arrival[index];
            wt[index] = tat[index] - burst[index];
            completed++;
            prev = -1;
        }
    }
    printf("%d\n", time);

    printf("\nPID  Arrival  Burst  Finish  TAT  WT\n");
    float tw = 0, tt = 0;
    for (int i = 0; i < n; i++)
    {
        printf("P%-3d %-8d %-6d %-7d %-4d %d\n", i + 1, arrival[i], burst[i], finish[i], tat[i], wt[i]);
        tw += wt[i];
        tt += tat[i];
    }

    printf("\nAvg Waiting Time    : %.2f\n", tw / n);
    printf("Avg Turnaround Time : %.2f\n", tt / n);

    return 0;
}
