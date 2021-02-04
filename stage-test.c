#include<stdio.h>
int stage1(int number)
{
    int sum=1;
    for(int i=1;i<=number;i++)
        sum=sum*i;
    return sum;
}
int stage2(int number)
{
    int sum=1;
    for(int i=number;i>0;i--)
        sum=sum*i;
    return sum;
}

int stage3(int number)
{
    int sum=1;
    for(int i=number;i>1;i--)
        sum*=i;
    return sum;
}

int main()
{
    int a;
    while(scanf("%d",&a))
    printf("%d  %d  %d\n",stage1(a),stage2(a),stage3(a));

}