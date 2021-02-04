#include<stdio.h>
#include<math.h>

int main()
{
    int x,y,pNum;
    scanf("%d%d",&x,&y);
    if(x<=2)
        printf("2 ");
    for(int i=x;i<=y;i++)
    {
        if(i%2==0||i==1)
        	continue;
        else 
        {
            pNum=1;
            for(int i1=2;i1<=sqrt(i);i1++)
            {
                if((i%i1)==0)
                    pNum=0;
            }
            if(pNum==1)
                printf("%d ",i);
        }
     }
        
    return 0;
}
