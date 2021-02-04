#include<stdio.h>
typedef unsigned long long ll;

ll combination(ll m,ll n)
{
    ll stage_im=1;//m!/n! or m!/(m-n)! depends on which one is smaller.
    ll stage_in=1;//n! or (m-n)!       depends on which one is smaller.

    int i = (n>(m-n)?  n  :(m-n));
    int i1= (n>(m-n)?(m-n):  n  );

    for(++i;i<=m;i++)
        stage_im*=i;

    for(int n=1;n<=i1;n++)
        stage_in*=n;

    ll combination=stage_im/stage_in;
    return combination;
}
int main()
{
    ll m,n;
    scanf("%lld%lld",&m,&n);
    printf("%lld",combination(m,n));
    return 0;
}