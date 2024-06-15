#include<iostream>
using namespace std;
int main()
{
    int n,k;
    int fact=1, fact1=1;
    cout<<"Fill in the blanks 2*_";
    cin>>n;
    cout<<"enter the number of the idectical tiles ";
    cin>>k;
    if (k==0)
    {
        fact1=1;
    }
    else 
    {
        for (int  i = k; i >1; i--)
        {
            fact1=fact1*i;
        }
        
    }
    if (n==0)
    {
        cout<<"1";
    }
    else
    { 
    for (int i = n; i > 1; i--)
    {
        fact =fact*i;
    }
    }
    cout<<"Number of ways this can be done :"<<fact/fact1;
    return 0;
    
}