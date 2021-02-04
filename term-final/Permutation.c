#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void permute(char* a,int l,int r);
int cmp(const void*,const void*);
void swap(char* a,char* b);
int main(void)
{
    char a[6];
    scanf("%s",a);
    qsort(a,strlen(a),sizeof(char),cmp);
    permute(a,0,strlen(a));
    return 0;
}

void permute(char* a,int l,int r)
{
    if(l==r)
    {
        printf("%s\n",a);
        return ;            //after printf,"b" below is useless,but "a" still useful.
    }
    for(int i=l;i<r;i++)
    {
        char b[r];//create a new string b to record father of the node.(or the father(a) will be changed                                                                 //,making)
        strcpy(b,a);                                                 //,making it wrong to do bubble sort below)
        swap(&b[l],&b[i]);
        for(int j=l+1;j<r;j++)
            for(int k=j+1;k<r;k++)
                if(b[j]>b[k])
                    swap(&b[j],&b[k]);
        permute(b,l+1,r);
    }
}
int cmp(const void* a,const void* b)
{
    return *(char*)a-*(char*)b;//* in front of (char*)a is necessary.
}
void swap(char* a,char* b)
{
    char temp=*a;
    *a=*b;
    *b=temp;
}
