#include<stdio.h>

int main()
{
    int i,n,T;
    printf("\nEnter total vale of share T: ");
    scanf("%d",&T);
    printf("\nEnter no. of processes: ");
    scanf("%d",&n);
    int N[n];
    double NT=0;

    for(i=0;i<n;i++)
    {
        printf("Enter share of P%d: ", i+1);
        scanf("%d",&N[i]);
        NT += (double)N[i]/T;
    }

    if(NT<=1)
        printf("\nProportionalShareSchedule is possible.\n");
    else
        printf("\nProportionalShareSchedule is not possible.\n");
}