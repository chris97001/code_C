#include <stdio.h>
//There is a sequence X which follows Xi= Xi-1+Xi-2 for any i>= 3.
//Given three integers X1,X2,n(where 0 <=X1,X2<= 30 , 2 <n<= 20), print out Xn.
int sequence_x(int x1, int x2, int n)
{
    if(n==1)
        return x1;
    else if(n==2)
        return x2;
    else
        return ((sequence_x(x1,x2,n-1))+(sequence_x(x1,x2,n-2)));
}

int main() {
int x1, x2, n;
scanf("%d%d%d", &x1, &x2, &n);
if(0<=x1&&x1<=30&&0<=x2&&x2<=30&&2<n&&n<=20){
    printf("%d", sequence_x(x1,x2, n));
}
    return 0;
}