#include<stdio.h>
int binary_search(int arr[], int x, int a )
{
    int left=0;
    int right =x;
    int mid=(left + right )/2;
    while (left< right  )
    {
         int mid =(left + right )/2;
         if (arr[mid]==a)
         {
            return mid;
         }
         else if  (arr[mid]>x)
         {
            
            right=mid-1;
         }
         else
         {
            left= mid +1;
         }
    }
    return -1;
}
int main ()
{
    int arr[]={1,2,5,22,33,88,99};
    int a, index;
    int x=sizeof(arr)/sizeof(arr[0]);
    //printf("%d\n",x);
    printf("enter the numbern to be searched ");
    scanf("%d",&a);
    index =binary_search(arr, x-1, a);
    if (index==-1)
    {
        printf("elemnet not found ");
    }
    else 
    {
    printf("your number is at : %d ",index );
    }
    return 0;
}
