#include<stdio.h>

int main()
{
	int n ,m ;
	printf("enter dimensions of both array");
	scanf("%d %d  ", &n, &m);
	int arr[m][n],a[m][n],add[m][n];
    for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
            add[m][n]=0;
        }
    }
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
    for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
    }
    for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
        {
                add[i][j]=add[i][j]+arr[i][j]+a[i][j];
        }
    }
        for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf (" %d ",add[i][j]);
		}
        printf("\n");
    }
    return 0;
}