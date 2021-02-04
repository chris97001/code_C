#include<stdio.h>
#include<string.h>

void add(char a[], char b[], char res[]);

int main(){
    char a[100], b[100], res[105];
    scanf("%s %s", a, b);
    add(a, b, res);
    printf("%s", res);
    return 0;
}

// Your code goes here
void swap(char* a, char* b)
{
    char temp=*b;
    *b=*a;
    *a=temp;
}
void reverse(char a[])
{
    for(int i=0;i<strlen(a)/2;i++)
        swap(&a[i],&a[strlen(a)-1-i]);
}
void print(char a[])
{
    for(int i=0;i<strlen(a);i++)
        printf("%c ",a[i]);
    printf("\n");
}
void add(char a[], char b[], char res[])
{
    char num1[100]={},
         num2[100]={};
    if(strlen(a)>=strlen(b))
    {
        strcpy(num1,a);
        strcpy(num2,b);
    }
    else
    {
        strcpy(num1,b);
        strcpy(num2,a);
    }
    reverse(num1);
    reverse(num2);
    int carry=0;
    int i;
    for(i=0;i<strlen(num2);i++)
    {
        res[i]=num1[i]-'0'+num2[i]-'0'+carry;
        carry=res[i]/10;
        res[i]%=10;
        res[i]+='0';
    }
    int temp=strlen(num1);
    num1[strlen(num1)]='0';
    for(i;i<=temp;i++)
    {
        res[i]=num1[i]-'0'+carry;
        carry=res[i]/10;
        res[i]%=10;
        res[i]+='0';
    }
    if(res[temp]=='0')
        res[temp]='\0';
    else
        res[temp+1]='\0';
    reverse(res);
}