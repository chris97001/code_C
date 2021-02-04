#include<stdio.h>
int main(){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    if(a>b)
    {
        if (a>c)
        {
            if(b>c)
            printf("%d",b);
            else
            printf("%d",c);
        }
        else
        printf("%d",a);
    }
    else if(a>c)
        printf("%d",a);
    else if (b>c)
    printf("%d",c);
    else
        printf("%d",b);
    
        


    /*int a,b,c,med;
    scanf("%d %d %d",&a,&b,&c);
    if(a>b)
    med=b>c?b:c;
    else if (a>c)
    med=b>c?b:c;
    else
    med=b>c?c:b;
    
    printf("%d",med);
*/
    return 0;
}
