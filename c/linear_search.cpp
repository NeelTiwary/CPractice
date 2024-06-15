#include<iostream>
using namespace std;
void linear_search(int a[],int size,int x)
{
    for (int  i = 0; i < size; i++)
    {
        if (a[i]==x)
        {
            cout<<"Element found at "<<i<<endl;
        }
    }
    
}
int main()
{
    int arr[]={1,4,3,6,8,6,3,7,8,9};
    int size = sizeof(arr)/sizeof(arr[0]);
    int x;
    cout<<"Enter the number to be searched";
    cin>>x;
    linear_search( arr , size , x);
    return 0;
}