// FCFS WITHOUT ARRIVAL TIME
#include<stdio.h>
struct process 
{
    int id;
    int BT;
    int CT;
    int WT;
    int TAT;
};
int main()
{
    int i,n;
    float TTAT  = 0 ,TWT = 0;
    printf("\nEnter the number of process : ");
    scanf("%d",&n);
    struct process p[n];
    for(i=0;i<n;i++)
    {
        p[i].id = i + 1;
        printf("\nEnter the burst time for each process p%d : ",i+1);
        scanf("%d",&p[i].BT);
    }
        int CRNT_time = 0;
    for(i=0;i<n;i++)
    {
        p[i].CT = CRNT_time + p[i].BT;
        p[i].TAT = p[i].CT;
        p[i].WT = p[i].TAT - p[i].BT;
        CRNT_time = p[i].CT;
    }
    printf("\nPID\tBT\tCT\tWT\tTAT\n");
    for(i=0;i<n;i++)
    {
        printf("\n%d\t%d\t%d\t%d\t%d\t",p[i].id,p[i].BT,p[i].CT,p[i].WT,p[i].TAT);
        TWT += p[i].WT;
        TTAT += p[i].TAT;
    }
    printf("\nTotal Waiting time = %.2f",TWT);
    printf("\nTotal Turnaround time = %.2f",TTAT);
    printf("\nAVg : Waiting time = %.2f",(float)TWT/n);
    printf("\nAvg : Turnaround time = %.2f",(float)TTAT/n);
    return 0;
}
