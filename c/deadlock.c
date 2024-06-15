#include<stdio.h>
int main()
{
    int size;
    printf("\n enter the number of the process");
    scanf("%d",&size);
    int max_need[][5]={{7,5,3},{3,2,2},{9,0,2},{2,2,2},{4,3,3}};
    int alloc[][5]={{0,1,0},{2,0,0},{3,0,2},{2,1,2},{0,0,2}};
    int need[][5];
    for (int i=0;i<3;i++)
    {
        for(int j=0;j<5;j++)
        {
            need[i][j]=max_need[i][j]-alloc[i][j];
        }
    }
    return 0;
}