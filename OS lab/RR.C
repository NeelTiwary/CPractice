#include <stdio.h>
#include <stdlib.h>
struct rr
{
int pid,btime,wtime,ttime,atime,ctime;
} p[10];
void shedule(int n,int qtime,int time[])
{
    for (int  i = 0; i < n; i++)
{
    if (time[i]>0)
    {
        time[i]=time[i]-qtime;
        p[i].ttime=p[i].ttime+qtime;
        p[i].ctime=p[i].ctime+qtime;
    }
}
for(int i=0;i<n;i++)
{
if(time[i]>0)
{
    shedule(n,qtime,time);
}
}

}
int main()
{
int i, n, qtime=1;
int totwtime = 0, totttime = 0;
printf("\nRR Scheduling...\n");
printf("Enter the number of processes: ");
scanf("%d", &n);
for (int i = 0; i < n; i++)
{
p[i].pid = i + 1;
int time[n];
printf("\nEnter the burst time of process, arrival time %d: ", p[i].pid);
scanf("%d", &p[i].btime);
scanf("%d",&p[i].atime);
}
for (int i = 0; i < n; i++)
{
    time[i]=p[i].btime;
}
shedule(n,qtime,time); 
printf("\nProcess\tWaiting Time\tTurnaround Time\tarrival time\n");
for (i = 0; i < n; i++)
{
printf("%d\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].wtime, p[i].ttime,p[i].atime);
}
printf("\nTotal Waiting Time: %d", totwtime);
printf("\nAverage Waiting Time: %.2f", (float)totwtime / n);
printf("\nTotal Turnaround Time: %d", totttime);
printf("\nAverage Turnaround Time: %.2f\n", (float)totttime / n);
return 0;
}