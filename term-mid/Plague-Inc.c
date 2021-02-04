#include<stdio.h>
int main()
{
    double R,people=1;
    int N,ans;
    scanf("%lf %d",&R,&N);
    for(int i=0;i<N;i++)
        people*=R;
    ans=people/1;
    printf("%d",ans);
    return 0;
}