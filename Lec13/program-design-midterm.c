/*
#include<stdio.h>
#include<math.h>
int main()
{
    int mode;
    double a,b,c,fourman=sqrt(2)/12;
    scanf("%d",&mode);
    
    if(mode==1) 
    {
        scanf("%lf",&a);
        printf("%.2lf",a*a*a);
    }
    else if(mode==2)
    {
        scanf("%lf %lf %lf",&a,&b,&c);
        printf("%.2lf",a*b*c);
    }
    else if(mode==3)
    {
        scanf("%lf %lf",&a,&b);
        printf("%.2lf",3.14*a*a*b);
    }
    else if(mode=4)
    {
        scanf("%lf",&a);
        printf("%.2lf",fourman*a*a*a);
    }
    return 0;
}
*/
/*
#include<stdio.h>
int main()
{
    double R,people=1;
    int N,ans;
    scanf("%lf %d",&R,&N);
    for(int i=0;i<N;i++)
        people*=R;
    ans=people/1;
    printf("%d",ans);
    return 0;
}
*/
/*
#include<stdio.h>
int main ()
{
    int m,n,temp;
    int number[10000];
    scanf("%d %d",&m,&n);
    for(int i=0;i<m+n;i++)
        scanf("%d",&number[i]);
    for(int i=m+n-1;i>=0;i--)
    {
        for (int j=0;j<i;j++)
        {
            if (number[j]>number[j+1])
            {
                temp=number[j];
                number[j]=number[j+1];
                number[j+1]=temp;
            }
        } 
    }
    for(int i=0;i<m+n;i++)
    printf("%d ",number[i]);
    return 0;
}
*/
/*
#include<stdio.h>
int main ()
{
    int degree;
    int m,n;
    scanf("%d",&degree);
    scanf("%d %d",&m,&n);
    int big=m>=n?m:n;
    int a[100][100]={},b[100][100]={},c[100][100]={},copy[100][100]={};
    int f;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    }
    for(int i=0;i<big;i++)
    {
        for(int j=0;j<big;j++)
            copy[i][j]=a[i][j];
    }
    for(int rotate=0;rotate<degree/90;rotate++)
    {
        //symmetrize
        for(int i=0;i<big;i++)
        {
            for(int j=0;j<big;j++)
            {
                b[i][j]=copy[j][i];
                copy[j][i]=0;//initialize used copy
            }
        }
        //reverse
        if(rotate==0||rotate==2)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=m-1,k=0;j>=0;j--,k++)
                    c[i][k]=b[i][j];
            }
        }
        else
        {
            for(int i=0;i<m;i++)
            {
                for(int j=n-1,k=0;j>=0;j--,k++)
                    c[i][k]=b[i][j];
            }
        }
        //copy the result
        for(int i=0;i<big;i++)
        {
            for(int j=0;j<big;j++)
                {
                copy[i][j]=c[i][j];
                c[i][j]=0;
                }//initialize used c
        }      
    }
    if(degree==90||degree==270)
    {
        for(int i=0;i<n;i++)
        {
        for(int j=0;j<m;j++)
            printf("%d ",copy[i][j]);
        printf("\n");
        }
    }
    else
    {
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                printf("%d ",copy[i][j]);
            }
            printf("\n");
        }
    }
    
    return 0;
}
*/
/*
#include<stdio.h>
int main()
{
    int a[50][50]={};
    int n;
    scanf("%d",&n);
    int m=n/2;
    a[0][m]=1;
    int i,x,y;
    for(i=1,x=m,y=0;i<n*n;i++)
    {
//first way
        int y1=y-1;
        if(y1<0)
            y1+=n;
        int x1=x+1;
        if(x1>=n)
            x1-=n;
//second way
        int y2=y+1;
        if(y2>=n)
            y2-=n;
        int x2=x;
        if(x2>=n)
            x2-=n;
        if(a[y1][x1]==0)
        {
            a[y1][x1]=i+1;
            x=x1;
            y=y1;
        }
        
        else
        {
            a[y2][x2]=i+1;
            y=y2;
            x=x2;
        }
        
            
        
        
    }
    for(i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        printf("%d ",a[i][j]);
        printf("\n");
    }
    return 0;
}
*/
/*
#include<stdio.h>
int main ()
{
    int length_of_key,i;
    unsigned char key[100],text;
    scanf("%d ",&length_of_key);
    for(i=0;i<length_of_key;i++)
        scanf(" %c",&key[i]);
    i=0;
    scanf("\n");
    while(text=getchar())
    {  
        if(text=='\n')
            break;
        i%=length_of_key;
        if(text>='A'&&text<='Z')
        {
            text+=(key[i]-'a');
            if (text>'Z')
                text-=26;
            i++;
        }
        if(text>='a'&&text<='z')
        {
            text+=(key[i]-'a');
            if (text>'z')
                text-=26;
            i++;
        }
        putchar(text);
    }
        
}
*/