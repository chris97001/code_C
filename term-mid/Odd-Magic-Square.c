/*
#include<stdio.h>
int main()
{
    int a[50][50]={};
    int n;
    scanf("%d",&n);
    int m=n/2;
    a[0][m]=1;
    int i,x,y;
    for(i=1,x=m,y=0;i<n*n;i++)
    {
        int y1=y-1;
        if(y1<0)
            y1+=n;
        int x1=x+1;
        if(x1>=n)
            x1-=n;
        int y2=y+1;
        if(y2>=n)
            y2-=n;
        int x2=x;
        if(x2>=n)
            x2-=n;

        if(a[y1][x1]==0)
        {
            a[y1][x1]=i+1;
            x=x1;
            y=y1;
        }
        else
        {
            a[y2][x2]=i+1;
            y=y2;
            x=x2;
        }
    }
    for(i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        printf("%d ",a[i][j]);
        printf("\n");
    }
    return 0;
}
*/
