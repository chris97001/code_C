#include<stdio.h>
int main()
{
    unsigned int a[10];
    unsigned int i;
    for(i=0;i<2;i++)
        scanf("%d",&(a[i]));
        printf("loop?\n");
    for(i=0;i<10;i++)
        printf("%d ",a[i]);
}