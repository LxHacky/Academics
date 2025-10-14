#include<stdio.h>
#include<stdlib.h>

struct process {
    int bt;
    int wt;
    int tat;
    int pid;
};
int main()
{
int n,i,j;
//Read no: of process
printf("\nEnter the no: of process : ");
scanf("%d",&n);
struct process p[n];
//Read BT
printf("\nEnter the burst time for each process : \n");
for(i=0;i<n;i++)
{
    scanf("%d",&p[i].bt);
    p[n].pid = i+1;
    p[i].wt = p[i].tat = 0; 
}
struct process tmp;
for(i=0;i<n;i++)
{
    for(j=0;j<n-i-1;j++)
    {
        if(p[j].bt > p[j+1].bt)
        {
            tmp = p[j];
            p[j] = p[j+1];
            p[j+1] = tmp;
        }
    }
}
int t_wt = 0,t_tat = 0;
//waitingtime
for(i=1;i<n;i++)
{
    p[i].wt = p[i-1].wt + p[i-1].bt;
    t_wt+=p[i].wt;
}
//turnaroundtime
for(i=0;i<n;i++)
{
    p[i].tat = p[i].wt + p[i].bt;
    t_tat += p[i].tat;
}
printf("\nPID\tBT\tWT\tTAT\n");
for(i=0;i<n;i++)
{
    printf("%3d\t%2d\t%2d\t%3d\n",p[i].pid,p[i].bt,p[i].wt,p[i].tat);
}
printf("Avg_Waitingtime = %2.f\n",(float)t_wt/n);
printf("Avg_Turnaroundtime = %2.f\n",(float)t_tat/n);
return 0 ;
}

