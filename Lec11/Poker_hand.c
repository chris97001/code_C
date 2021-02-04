#include<stdio.h>
int r_int(char);                        //turn char form to int(suit)
int s_int(char);                        //turn char form to int(rank)
void sort(int rank[],int suit[]);       //bubble sort
void swap(int *a,int *b);               //swap function used in sort above
void swap_c(char *a,char *b);           //swap function for char
int check_sf(int rank[],int suit[]);    //check if it's straight flush
int check_foak(int rank[]);             //check if it's four-of-a-kind
int check_fh(int rank[]);               //check if it's full house
int check_flush (int suit[]);
int check_straight(int rank[]);
int check_toak(int rank[]);             //check if it's three-of-a-kind
int check_tp(int rank[]);               //check if it's two pairs
int check_pairs(int rank[]);            //check if it's pair
int order_rank(int rank[],int suit[]);  //determine the order of A,B,C,D
void compare(int* order,int rank[],int suit[],int* order1,int rank1[],int suit1[]);//compare same rank
int main()
{
    int Arank[5],Brank[5],Crank[5],Drank[5];
    int Asuit[5],Bsuit[5],Csuit[5],Dsuit[5];
    char r,s;

    for(int i=0;i<5;i++)
    {
        scanf(" %1c %1c",&r,&s);
        Arank[i]=r_int(r);
        Asuit[i]=s_int(s);
    }
    for(int i=0;i<5;i++)
    {
        scanf(" %1c %1c",&r,&s);
        Brank[i]=r_int(r);
        Bsuit[i]=s_int(s);
    }
    for(int i=0;i<5;i++)
    {
        scanf(" %1c %1c",&r,&s);
        Crank[i]=r_int(r);
        Csuit[i]=s_int(s);
    }
    for(int i=0;i<5;i++)
    {
        scanf(" %1c %1c",&r,&s);
        Drank[i]=r_int(r);
        Dsuit[i]=s_int(s);
    }

    sort(Arank,Asuit);
    sort(Brank,Bsuit);
    sort(Crank,Csuit);
    sort(Drank,Dsuit);

    int order_int[4];
    char order_char[4];
    order_int[0]=order_rank(Arank,Asuit);
    order_char[0]='A';
    order_int[1]=order_rank(Brank,Bsuit);
    order_char[1]='B';
    order_int[2]=order_rank(Crank,Csuit);
    order_char[2]='C';
    order_int[3]=order_rank(Drank,Dsuit);
    order_char[3]='D';

    for(int i=0;i<3;i++)
        for(int j=i+1;j<4;j++)
        {
            if(order_int[i]<order_int[j]+4&&order_int[i]>order_int[j]-4)//order A and B are in a range of 4 for example:35 40 45
            {
                int rank[5]={},suit[5]={},rank1[5]={},suit1[5]={};
                if(order_char[i]=='A')
                    for(int k=0;k<5;k++)
                    {
                        rank[k]=Arank[k];
                        suit[k]=Asuit[k];
                    }
                else if(order_char[i]=='B')
                    for(int k=0;k<5;k++)
                    {
                        rank[k]=Brank[k];
                        suit[k]=Bsuit[k];
                    }
                else if(order_char[i]=='C')
                    for(int k=0;k<5;k++)
                    {
                        rank[k]=Crank[k];
                        suit[k]=Csuit[k];
                    }
                else if(order_char[i]=='D')
                    for(int k=0;k<5;k++)
                    {
                        rank[k]=Drank[k];
                        suit[k]=Dsuit[k];
                    }
                //j
                if(order_char[j]=='A')
                    for(int k=0;k<5;k++)
                    {
                        rank1[k]=Arank[k];
                        suit1[k]=Asuit[k];
                    }
                else if(order_char[j]=='B')
                    for(int k=0;k<5;k++)
                    {
                        rank1[k]=Brank[k];
                        suit1[k]=Bsuit[k];
                    }
                else if(order_char[j]=='C')
                    for(int k=0;k<5;k++)
                    {
                        rank1[k]=Crank[k];
                        suit1[k]=Csuit[k];
                    }
                else if(order_char[j]=='D')
                    for(int k=0;k<5;k++)
                    {
                        rank1[k]=Drank[k];
                        suit1[k]=Dsuit[k];
                    }
                compare(&order_int[i],rank,suit,&order_int[j],rank1,suit1);
            }          
        }
    for(int i=0;i<3;i++)
        for(int j=i+1;j<4;j++)
        {
            if(order_int[i]<order_int[j])
            {
                swap(&order_int[i],&order_int[j]);
                swap_c(&order_char[i],&order_char[j]);
            }
        }
    for(int i=0;i<4;i++)
        printf("%c ",order_char[i]);
}
int r_int(char r)
{
    int R;
    switch(r)
    {
        case '2':R= 0; break;
        case '3':R= 1; break;
        case '4':R= 2; break;
        case '5':R= 3; break;
        case '6':R= 4; break;
        case '7':R= 5; break;
        case '8':R= 6; break;
        case '9':R= 7; break;
        case 't':R= 8; break;
        case 'j':R= 9; break;
        case 'q':R= 10;break;
        case 'k':R= 11;break;
        case 'a':R= 12;break;
    }
    return R;
}
int s_int(char s)
{
    int S;
    switch(s)
    {
        case 'c':S= 0;break;
        case 'd':S= 1;break;
        case 'h':S= 2;break;
        case 's':S= 3;break;
    }
    return S;
}
void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void swap_c(char *a,char*b)
{
    char temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void sort(int rank[],int suit[])
{
    //sort the rank
    for(int i=0;i<4;i++)
        for(int j=i+1;j<5;j++)
        {
            if(rank[i]>rank[j])
            {
                swap(&rank[i],&rank[j]);//add & to let the pointer points to the position of rank[i]
                swap(&suit[i],&suit[j]);
            }
        }
    //sort the suit of same rank
    for(int i=0;i<4;i++)
        for(int j=i+1;j<5;j++)
        {
            if(rank[i]==rank[j])
            {
                if(suit[i]>suit[j])
                    swap(&suit[i],&suit[j]);
            }
        }
                
}
int check_sf(int rank[],int suit[])
{
    if(check_flush(suit)&&check_straight(rank))
        return 1;
    else
        return 0;
}
int check_foak(int rank[])
{
    int count=0;
    for(int i=1;i<5;i++)
        if(rank[i-1]==rank[i])
            count++;
    if(count==3&&rank[1]==rank[3])//separate AAAAB from AAABB or AABBB(which causes count=3)
        return 1;
        
    else
        return 0;
}
int check_fh(int rank[])
{
    if (rank[0]==rank[1]&&rank[1]==rank[2]&&rank[3]==rank[4])//AAA BB
        return 1; 
    else if(rank[0]==rank[1]&&rank[2]==rank[3]&&rank[3]==rank[4])//BB AAA
        return 1;
    else
        return 0;
}
int check_flush (int suit[])
{
    int count_s=0;
    for(int i=1;i<5;i++)
            if(suit[i]==suit[i-1])
                count_s++;
    if(count_s==4) 
        return 1;
    else
        return 0;
}
int check_straight (int rank[])
{
    int count_r=0;
    for(int i=1;i<5;i++)
        if(rank[i]==rank[i-1]+1||(rank[i]==12&&rank[i-1]==3))//A(12) to 2(0=(12+1)%13) is also a straight
            count_r++;
    if (count_r==4)
        return 1;
    else
        return 0;
}
int check_toak(int rank[])
{
    int count_r=0;
    for(int i=0;i<4;i++)
        for(int j=i+1;j<5;j++)
            if(rank[i]==rank[j])
                count_r++;
    if(count_r==3)
        return 1;
    else
        return 0;
}
int check_tp(int rank[])
{
    int count_r=0;
    for(int i=0;i<4;i++)
        for(int j=i+1;j<5;j++)
            if(rank[i]==rank[j])
                count_r++;
    if(count_r==2)
        return 1;
    else
        return 0;
}
int check_pairs(int rank[])
{
    int count_r=0;
    for(int i=0;i<4;i++)
        for(int j=i+1;j<5;j++)
            if(rank[i]==rank[j])
                count_r++;
    if(count_r==1)
        return 1;
    else
        return 0;
}
int order_rank(int rank[],int suit[])
{
    if(check_sf(rank,suit))
        return 80;
    if(check_foak(rank))
        return 70;
    if(check_fh(rank))
        return 60;
    if(check_flush(suit))
        return 50;
    if(check_straight(rank))
        return 40;
    if(check_toak(rank))
        return 30;
    if(check_tp(rank))
        return 20;
    if(check_pairs(rank))
        return 10;
    else
        return 0;
}
void compare(int* order,int rank[],int suit[],int* order1,int rank1[],int suit1[])
{
    if(*order>=80||(*order>=50&&*order<60)||(*order>=40&&*order<=50)||(*order>=0&&*order<10))//straight flush or flush or straight
    {
        if(rank[4]>rank1[4])
            ++*order;
        else if(rank[4]<rank1[4])
            ++*order1;
        else if(rank[4]==rank1[4])
        {
            if(suit[4]>suit1[4])
                ++*order;
            else
                ++*order1;
        }
    }
    else if((*order>=70&&*order<80)||(*order>=60&&*order<70)||(*order>=30&&*order<40))//four-of-a-kind or full house or three-of-a-kind
    {
        if(rank[2]>rank1[2])
            ++*order;
        else
            ++*order1;
    }
    else if(*order>=20&&*order<30)
    {
        if(rank[3]>rank1[3])
            ++*order;
        else if(rank[3]<rank1[3])
            ++*order1;
        else if(rank[3]==rank1[3])
        {
            if(rank[2]==rank[3]&&rank1[2]==rank[3])//AABBC AABBC
            {
                if(suit[3]>suit1[3])
                    ++*order;
                else
                    ++*order1;
            }
            else if(rank[2]==rank[3]&&rank1[3]==rank[4])//AABBC AABCC
            {
                if(suit[3]>suit1[4])
                    ++*order;
                else
                    ++*order1;
            }
            else if(rank[3]==rank[4]&&rank1[2]==rank[3])//AABCC AABBC
            {
                if(suit[4]>suit1[3])
                    ++*order;
                else
                    ++*order1;
            }
            else if(rank[3]==rank[4]&&rank1[3]==rank[4])//AABCC AABCC
            {
                if(suit[4]>suit1[4])
                    ++*order;
                else
                    ++*order1;
            }
        }
    }
    else if(*order>=10&&*order<20)
    {
        int r,r1,s,s1;
        for(int i=0;i<4;i++)
        {
            if(rank[i+1]==rank[i])
            {
                r=rank[i+1];
                s=suit[i+1];
            } 
            if(rank1[i+1]==rank1[i])
            {
                r1=rank1[i+1];
                s1=suit1[i+1];
            }
        }
        if(r>r1)
            ++*order;
        else if(r<r1)
            ++*order1;
        else if(r==r1)
        {
            if(s>s1)
                ++*order;
            else
                ++*order1;
        }
    }
}