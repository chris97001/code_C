#include<stdio.h>
int main()
{
    int num1[32],num2[32],sum[32],carry=0;
    for(int i=0;i<32;i++)
        scanf("%d",&num1[i]);
    for(int i=0;i<32;i++)
        scanf("%d",&num2[i]);
    for(int i=31;i>=0;i--)
    {
        sum[i]=num1[i]+num2[i]+carry;
        carry=sum[i]/2;
        sum[i]%=2;
    }   
    for(int i=0;i<32;i++)
        printf("%d ",sum[i]);
    return 0;
}