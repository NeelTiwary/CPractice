#include <stdio.h>
#include <limits.h>

#define MAX_PROCESS 10

struct Process {
    int id;
    int arrivalTime;
    int burstTime;
    int completionTime;
};

void calculateCompletionTime(struct Process processes[], int n) {
    int currentTime = 0; // Current time
    int completed = 0;

    while (completed < n) {
        int shortestJob = -1;
        int shortestBurst = INT_MAX;

        // Find the shortest job among the remaining processes that have arrived
        for (int i = 0; i < n; i++) {
            if (processes[i].arrivalTime <= currentTime && processes[i].completionTime == -1) {
                if (processes[i].burstTime < shortestBurst) {
                    shortestBurst = processes[i].burstTime;
                    shortestJob = i;
                }
            }
        }

        if (shortestJob != -1) {
            processes[shortestJob].completionTime = currentTime + processes[shortestJob].burstTime;
            currentTime = processes[shortestJob].completionTime;
            completed++;
        } else {
            // If no process is available, simply increment the current time
            currentTime++;
        }
    }
}

void displayGanttChart(struct Process processes[], int n) {
    // Sort processes based on completion time for Gantt chart
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].completionTime > processes[j + 1].completionTime) {
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    printf("Gantt Chart:\n");
    for (int i = 0; i < n; i++) {
        printf("| P%d ", processes[i].id);
    }
    printf("|\n");

    printf("0");
    for (int i = 0; i < n; i++) {
        printf("    %d", processes[i].completionTime);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[MAX_PROCESS];

    printf("Enter arrival time and burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Process P%d:\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &processes[i].arrivalTime);
        printf("Burst Time: ");
        scanf("%d", &processes[i].burstTime);
        processes[i].completionTime = -1; // Initialize completion time to -1
    }

    // Sort processes based on arrival time
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].arrivalTime > processes[j + 1].arrivalTime) {
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    calculateCompletionTime(processes, n);
    displayGanttChart(processes, n);

    // Calculate and display the turnaround time and waiting time
    float total_turnaround_time = 0, total_waiting_time = 0;
    for (int i = 0; i < n; i++) {
        float turnaround_time = processes[i].completionTime - processes[i].arrivalTime;
        float waiting_time = turnaround_time - processes[i].burstTime;
        total_turnaround_time += turnaround_time;
        total_waiting_time += waiting_time;
    }

    printf("Average Turnaround Time: %.2f\n", total_turnaround_time / n);
    printf("Average Waiting Time: %.2f\n", total_waiting_time / n);

    return 0;
}