#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    //int *deck=(int*)malloc(sizeof(int)*n);
    int deck[n];
    for(int i=0;i<n;i++)
        deck[i]=i+1;
    for(int i=0;i<m;i++)
    {
        int j;
        printf("%d ",deck[0]);
        for(j=0;j<n-1;j++)
            deck[j]=deck[j+1];
        int temp=deck[0];//otherwise deck[0] will disappear
        for(j=0;j<n-2;j++)
            deck[j]=deck[j+1];
        deck[j]=temp;
        n--;
    }
    return 0;
}