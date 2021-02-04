#include<stdio.h>
int stage(int number)
{
    int sum=1;
    for(int i=1;i<=number;i++)
        sum*=i;
    return sum;
}

int main()
{
    int number,digit;
    int numberA,numberB,numberC,sum=0;
    scanf("%d",&number);
    numberA=number;
    numberB=number;
    for(digit=0;numberA>0;digit++)
        numberA/=10;
    for(int i=0;i<digit;i++)
    {
        numberC=numberB%10;
        sum+=stage(numberC);
        numberB/=10;
    }
    if(sum==number)
        printf("%d is a strong number.",number);
    else
        printf("%d is not a strong number.",number);
    
    return 0;
    
}
