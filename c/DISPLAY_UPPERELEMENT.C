#include<stdio.h>
int n;
int main()
{
	printf("enter dimensions of  array");
	scanf("%d ", &n);
	int arr[n][n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
    for(int i=0;i<n;i++)
        for(int j=0; j<n; j++)
        {
            if (i==j)
            {
                printf(" diagonal elements : %d \n ",arr[i][j]);

            }
            if (i>j)
            {
                print(" lower triangle : %d \n ",arr[i][j]);
            }
            if (j>i)
            {
                printf("upper triangle : %d \n", arr[i][j]);
            }
            return 0;
        }
    
    
}
