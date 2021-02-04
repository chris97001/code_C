#include<stdio.h>
int swap(int a,int b)
{
    int temp;
    temp=a;
    a=b;
    b=temp;
    return a,b;
}
void pointswap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int main()
{
    int a,b,m,n;
    scanf("%d%d",&a,&b);
    m=a;
    n=b;
    swap(a,b);
    pointswap(&m,&n);
    printf("%d %d %d %d\n",a,b,m,n);
}