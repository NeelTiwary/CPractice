#include<stdio.h>

int main()
{
	int n ,m ,p,q;
	printf("enter dimensions of both array");
	scanf("%d %d %d %d ", &n, &m, &p ,&q);
	int arr[m][n],a[p][q],mul[m][q];
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	for(int i=0;i<p;i++)
	{
		for(int j=0;j<q;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<q;j++)
		{
			mul[i][j]=0;
		}
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<q;j++)
		{
			for(int k=0;k<n;k++)
			{
				mul[i][j]=mul[i][j]+arr[i][k]*a[k][j];
				
			}
		}
	}	
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<q;j++)
		{
			printf("%d ",mul[i][j]);
		}
		printf("\n");
	}
	return 0;
}