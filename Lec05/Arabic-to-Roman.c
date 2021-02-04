#include<stdio.h>

int main(){
    int a,temp;
    scanf("%d",&a);
    int ia1000=a/1000;
        while(ia1000>0)
        {
            printf("M");
            ia1000--;
        }
//1000
    int ia100=(a%1000)/100;
    if(ia100!=4 && ia100!=9)
    {
        if(ia100>=5)
        {
            ia100-=5;
            printf("D");
        }
        while(ia100>0)
        {
            printf("C");
            ia100--;
        }
    }
    if(ia100==4)
    printf("CD");
    if(ia100==9)
    printf("CM");
//100
    int ia10=(a%100)/10;
    if(ia10!=4 && ia10!=9)
    {
        if(ia10>=5)
        {
            ia10-=5;
            printf("L");
        }
        while(ia10>0)
        {
            printf("X");
            ia10--;
        }
    }
    if(ia10==4)
    printf("XL");
    if(ia10==9)
    printf("XC");
//10
    int ia1=a%10;
    if(ia1!=4 && ia1!=9)
    {
        if(ia1>=5)
        {
            ia1-=5;
            printf("V");
        }
        while(ia1>0)
        {
            printf("I");
            ia1--;
        }
    }
    if(ia1==4)
    printf("IV");
    if(ia1==9)
    printf("IX");
    return 0;
}
