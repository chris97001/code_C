/*#include<stdio.h>
int main()
{
    char a[4]={' '};
    char b[4]={' '};
    char ans;
    //a[0]=getchar();
    scanf("%s",&a[0]);
    scanf("%s",&b[0]);
    //printf("%c\n",a[0]);
    for(int i=0;i<4;i++)
        printf("%c %c ",a[i],b[i]);

}*/
#include<stdio.h>
#include<string.h>
char a[501],b[501],c[1001];
char operation;
int a_length;
int b_length;
int swap(int m,int n)
{
    int temp;
    temp=m;
    m=n;
    n=temp;
    return m,n;
}
void add(a,b)
{


}
void subtract()
{

}
void mul()
{

}
void div()
{

}
int main()
{
    while(scanf("%s %c %s ",a,&operation,b))
    {
        a_length=strlen(a);
        b_length=strlen(b);
        if(operation=='+')
            add(a,b);
        if(operation=='-')
            subtract(a,b);
        if(operation=='*')
            mul(a,b);
        if(operation=='/')
            div(a,b);
    }
    
    return 0;
}
