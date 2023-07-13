#include <stdio.h>

#define MAX_PROCESSES 10

void roundRobin(int n, int bt[], int quantum, int tat[]) {
    int rem_bt[MAX_PROCESSES], wt[MAX_PROCESSES], i;
    int total_wt = 0, total_time = 0,totaltat=0;

    // Make a copy of burst times
    for (i = 0; i < n; i++)
        rem_bt[i] = bt[i];

    // Traverse processes while they are not done
    while (1) {
        int flag = 1;

        // Traverse all processes
        for (i = 0; i < n; i++) {
            // If burt time remaining for the process
            if (rem_bt[i] > 0) {
                flag = 0; // There is still a pending process

                // If burst time is greater than quantum
                if (rem_bt[i] > quantum) {
                    total_time += quantum;
                    rem_bt[i] -= quantum;
                } else {
                    // Last cycle for this process
                    total_time += rem_bt[i];
                    wt[i] = total_time - bt[i];
                    rem_bt[i] = 0;
                }
            }
        }

        // If all processes are done
        if (flag == 1)
            break;
    }

    // Calculate total waiting timee
    for (i = 0; i < n; i++){
        total_wt += wt[i];
        tat[i]=bt[i]+wt[i];

        }

    for(int i=0;i<n;i++){
        totaltat+=tat[i];
    }
    // Print result
    printf("Process\tBurst Time\tWaiting Time\tturn around time\n");
    for (i = 0; i < n; i++)
        printf("%d\t%d\t\t%d\t%d\n", i, bt[i], wt[i],tat[i]);
    printf("Average waiting time: %f\n Average turn Around time %f", (float)total_wt / n , (float)totaltat/n);
}

void main() {
    int n, i, bt[MAX_PROCESSES], quantum,tat[MAX_PROCESSES];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter burst time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d: ", i);
        scanf("%d", &bt[i]);
    }

    printf("Enter the quantum size: ");
    scanf("%d", &quantum);

    roundRobin(n, bt, quantum,tat);

}
