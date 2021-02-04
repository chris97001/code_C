#include<stdio.h>
int main()
{
    int Ahp,Bhp,attack;
    scanf("%d %d",&Ahp,&Bhp);
    while(Ahp>0&&Bhp>0)
    {
        scanf("%d",&attack);
            Bhp-=attack;
        if(Bhp<=0)
            break;
        scanf("%d",&attack);
            Ahp-=attack;
    }
    if(Ahp<=0)
        printf("B");
    else
        printf("A");
        
    
    return 0;
}
