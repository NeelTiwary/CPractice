#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
#define MAX_PROCESS 10

struct Process {
    int id;
    int arrivalTime;
    int burstTime;
    int priority;
    int completionTime;
};

void calculateCompletionTime(struct Process processes[], int n) {
    int current_time = 0; 

    int arrived[MAX_PROCESS] = {0};

    for (int i = 0; i < n; i++) {
        int highest_priority = INT_MAX;
        int selected_process = -1;

        for (int j = 0; j < n; j++) {
            if (processes[j].arrivalTime <= current_time && processes[j].completionTime == -1 && processes[j].priority < highest_priority) {
                highest_priority = processes[j].priority;
                selected_process = j;
            }
        }

        if (selected_process != -1) {
            processes[selected_process].completionTime = current_time + processes[selected_process].burstTime;
            current_time = processes[selected_process].completionTime;
            arrived[selected_process] = 1;
        } else {
            current_time++;
        }
    }
}

void displayGanttChart(struct Process processes[], int n) {
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
        printf("| P%d  ", processes[i].id);
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

    printf("Enter arrival time, burst time, and priority for each process:\n");
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Process P%d:\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &processes[i].arrivalTime);
        printf("Burst Time: ");
        scanf("%d", &processes[i].burstTime);
        printf("Priority: ");
        scanf("%d", &processes[i].priority);
        processes[i].completionTime = -1; 
    }

    calculateCompletionTime(processes, n);
    displayGanttChart(processes, n);

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