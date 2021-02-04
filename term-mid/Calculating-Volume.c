#include<stdio.h>
#include<math.h>
int main()
{
    int mode;
    double a,b,c,fourman=sqrt(2)/12;
    scanf("%d",&mode);
    
    if(mode==1) 
    {
        scanf("%lf",&a);
        printf("%.2lf",a*a*a);
    }
    else if(mode==2)
    {
        scanf("%lf %lf %lf",&a,&b,&c);
        printf("%.2lf",a*b*c);
    }
    else if(mode==3)
    {
        scanf("%lf %lf",&a,&b);
        printf("%.2lf",3.14*a*a*b);
    }
    else if(mode=4)
    {
        scanf("%lf",&a);
        printf("%.2lf",fourman*a*a*a);
    }
    return 0;
}