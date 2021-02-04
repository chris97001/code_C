#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int m[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            scanf("%d",&m[i][j]);
    }
    int sym=0;
    int sym_total=n*n-n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(j!=i&&m[i][j]==m[j][i])
                sym++;
        }
    }
    if(sym==sym_total)
        printf("Yes");
    else
        printf("No");
    
}