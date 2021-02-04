#include<stdio.h>
int main()
{
    int month,space=0;
    int days=3;//start from Wed
    scanf("%d",&month);
    printf("Sun Mon Tue Wed Thu Fri Sat \n");

    switch(month)
        {
            case 12:days+=30;
            case 11:days+=31;
            case 10:days+=30;
            case 9 :days+=31;
            case 8 :days+=31;
            case 7 :days+=30;
            case 6 :days+=31;
            case 5 :days+=30;
            case 4 :days+=31;
            case 3 :days+=29;
            case 2 :days+=31;
        }
    //print space before 1st day
    space=days%7;
    for(int i=0;i<space;i++)
        printf("    ");
    //calender
    int days_of_month;
    if (month==1||month==3||month==5||month==7||month==8||month==10||month==12)
        days_of_month=31;
    else if(month==2)
        days_of_month=29;
    else
        days_of_month=30;
    for(int i=1;i<=days_of_month;i++)
    {
        printf("%3d ",i);
        space++;
        if(space==7&&i!=days_of_month)//if i is the last day,we don't have to \n
        {
            printf("\n");
            space=0;
        }
    }
    return 0;
}