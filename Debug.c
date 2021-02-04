#include<stdio.h>
int main()
{
    int a[9][9];
    for(int j=1;j<10;j++)
    {
        for(int i=1;i<10;i++)
        {
            a[j-1][i-1]=j*i;
            printf("%d\t",a[j-1][i-1]);
        }
        printf("\n");
    }
    printf("\n");
    int (*p)[9]=a;
    printf("%d",(p[1][5]));
    return 0;
}