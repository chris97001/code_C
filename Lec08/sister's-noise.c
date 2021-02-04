#include<stdio.h>
int main()
{
    int sister[10],house,noise,max=0;
    for(house=0;house<10;house++)
        scanf("%d",&sister[house]);
    for(house=9;house>=0;house--)
    {
        for(int i=0;i<house;i++)
        {
            noise=(sister[house]-sister[i])*(house-i);
            if(noise>max)
                max=noise;
        }
    }
    printf("%d",max);
    return 0;
}