#include<stdio.h>
int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    printf("%.2d:%.2d",a+(b+50)/60,(b+50)%60);
}