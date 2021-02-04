#include<stdio.h>
int main()
{
    char a;
    while(a=getchar())
    {
       /* while(1)
        {
        a=getchar();
        if(a==EOF)
            break;*/
        if(a=='\n')
            break;
        if(a=='A')
            printf("C");
        if(a=='B')
            printf("R");
        if(a=='C')
            printf("W");
        if(a=='D')
            printf("Z");
        if(a=='E')
            printf("G");
    }

    return 0;
}