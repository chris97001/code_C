#include<stdio.h>
int main ()
{
    int space=0;
    char a,b;
    while(a=getchar())
    {
        if(a=='\n')
            break;
        if(a==' ')
        {
            if(space==0)
            {
                space=1;
                printf(" ");
                continue;
            }
            if(space==1)
                continue;
            
        }
        if(a!=' ')            
            space=0;    //initialize space,when a!=space 
        b=a;
        
        printf("%c",b);
    }
    return 0;
}