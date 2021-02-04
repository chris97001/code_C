#include<stdio.h>
int main ()
{
    int degree;
    int m,n;
    scanf("%d",&degree);
    scanf("%d %d",&m,&n);
    int big=m>=n?m:n;
    int a[100][100]={},b[100][100]={},c[100][100]={},copy[100][100]={};
    int f;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    }
    for(f=0;f<degree/90;f++)
    {
        if(f==0)
            for(int i=0;i<big;i++)
                for(int j=0;j<big;j++)
                    copy[i][j]=a[i][j];
        else
        {
            for(int i=0;i<big;i++)
                for(int j=0;j<big;j++)
                    b[i][j]=copy[j][i];
            if(f==0||f==2)
                for(int i=0;i<n;i++)
                    for(int j=m-1,k=0;j>=0;j--,k++)
                        c[i][k]=b[i][j];
            else
            {
                for(int i=0;i<m;i++)
                    for(int j=n-1,k=0;j>=0;j--,k++)
                        c[i][k]=b[i][j];

                for(int i=0;i<big;i++)
                    for(int j=0;j<big;j++)
                        copy[i][j]=c[i][j];
            }
        }
        if(degree==90||degree==270)
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                    printf("%d ",c[i][j]);
                printf("\n");
            }
    }
    else
    {
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
                printf("%d ",c[i][j]);
            printf("\n");
        }
    }
    return 0;
}