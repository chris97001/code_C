#include<stdio.h>
int stage(int number)
{
    int sum=number;
    for(int i=1;i<number;i++)
        sum*=(number-i);
    return sum;
}

int main()
{
    long long number,digit;
    long long numberA,numberB,numberC,sum=0;
    for(number=0;number<=500000;number++)
    {
    numberA=number;
    numberB=number;
    for(digit=0;numberA>0;digit++)
        numberA/=10;
    for(long long i=0;i<digit;i++)
    {
        numberC=numberB%10;
        sum+=stage(numberC);
        numberB/=10;
    }
    if(sum==number)
        printf("%d\n",number);
    sum=0;
    numberA=0;
    numberB=0;
    numberC=0;
    digit=0;

    }
    
    return 0;
    
}
