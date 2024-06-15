#include <stdio.h>
#include <stdlib.h>
struct fcfs
{
int pid,btime,wtime,ttime,atime;
} p[10];
int main()
{
int i, n;
int totwtime = 0, totttime = 0;
printf("\nFCFS Scheduling...\n");
printf("Enter the number of processes: ");
scanf("%d", &n);
for (i = 0; i < n; i++)
{
p[i].pid = i + 1;
printf("\nEnter the burst time of process, arrival time %d: ", p[i].pid);
scanf("%d", &p[i].btime);
scanf("%d",&p[i].atime);
}
p[0].wtime = 0;
p[0].ttime = p[0].btime;
totttime += p[0].ttime;
for (i = 1; i < n; i++)
{
p[i].wtime = p[i - 1].wtime + p[i - 1].btime;
p[i].ttime = p[i].wtime + p[i].btime;
totttime += p[i].ttime;
totwtime += p[i].wtime;
}
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