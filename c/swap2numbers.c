#include<stdio.h>
void swap (int *a, int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int main()
{
    int a=20;
    int b=30;
    swap(&a,&b);
    printf("%d ",a );
    printf("%d",b);
    return 0;

}