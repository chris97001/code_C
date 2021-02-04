#include<stdio.h>
int main()
{
    int a,n,x,b;
    scanf("%d%d%d",&n,&x,&a);
    b=(a+x)%n;
    printf("%d",b);
    return 0;
}