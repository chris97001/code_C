#include<stdio.h>

int main(){
    char str[1000];
    int i,n;
    scanf("%d ",&n);
    for(i=0;i<n;i++)
        str[i]=getchar();
    for(i-=1;i>=0;i--)
        putchar(str[i]);
        
    return 0;
}