// fcfs code 
#include <stdio.h>
#include <stdlib.h>

void waitingtime(int proc[], int n, int burst_time[], int wait_time[])
{
    wait_time[0] = 0;
    for (int i = 1; i < n; i++)
    {
        wait_time[i] = burst_time[i - 1] + wait_time[i - 1];
    }
}

void turnaroundtime(int proc[], int n, int burst_time[], int wait_time[], int tat[])
{
    for (int i = 0; i < n; i++)
        tat[i] = burst_time[i] + wait_time[i];
}

void avgtime(int proc[], int n, int burst_time[])
{
    int wait_time[n], tat[n], total_wt = 0, total_tat = 0;
    waitingtime(proc, n, burst_time, wait_time);
    turnaroundtime(proc, n, burst_time, wait_time, tat);
    for (int i = 0; i < n; i++)
    {
        total_wt += wait_time[i];
        total_tat += tat[i];
        printf("\n Process :%d  Burst Time:%d Wait Time:%d  Turnaround time:%d", proc[i], burst_time[i], wait_time[i], tat[i]);
    }
    printf("\nAverage wait time:%d  Average turnaround time:%d \n", total_wt / n, total_tat / n);
}
// extra block of code to sort for priority

void sort(int proc[],int burst_time[],int n,int priority[]){
    int a,b,c;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(priority[i]>priority[j]){
                // swap burst_time
                a=burst_time[i];
                burst_time[i]=burst_time[j];
                burst_time[j]=a;
                // swap proc accordingly
                b=proc[i];
                proc[i]=proc[j];
                proc[j]=b;
                // swap priority
                c=priority[i];
                priority[i]=priority[j];
                priority[j]=c;
            }
        }
    }
}

void main()
{
    int proc[10], burst_time[10], n,priority[10];
    printf("\n Enter the size of n:");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter the processor number:");
        scanf("%d", &proc[i]);
        printf("Enter the burst time:");
        scanf("%d", &burst_time[i]);
        printf("enter the priority: ");
        scanf("%d",&priority[i]);
    }

    printf("\n");
    sort(proc,burst_time,n,priority);
    avgtime(proc, n, burst_time);
}
