#include<stdio.h>
int main ()
{
    int m,n,temp;
    int number[10000];
    scanf("%d %d",&m,&n);
    for(int i=0;i<m+n;i++)
        scanf("%d",&number[i]);
    for(int i=m+n-1;i>=0;i--)
    {
        for (int j=0;j<i;j++)
        {
            if (number[j]>number[j+1])
            {
                temp=number[j];
                number[j]=number[j+1];
                number[j+1]=temp;
            }
        } 
    }
    for(int i=0;i<m+n;i++)
    printf("%d ",number[i]);
    return 0;
}