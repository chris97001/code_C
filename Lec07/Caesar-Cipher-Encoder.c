#include<stdio.h>
int main()
{   
    int k;
    //char a;
    unsigned char a;//this will fix the overflow
    scanf("%d ",&k);
    k%=26;
    while(a=getchar())
    {
        if(a=='\n')
            break;

        if(a>='A'&& a<='Z')
        {
            a+=k;
            if(a>'Z')
                a=a-'Z'+'A'-1;      //if we don't minus 1,A(56) would be Z(81))
            if(a<'A')
                a=a-'A'+'Z'+1;
        }          
        
        if(a>='a'&& a<='z')
        {
            //a-='a';                 //to prevent char a from overflow
            a+=k;
            if(a>'z')//-'a'))
                a=a-'z'+'a'-1;//+'a';
            else if(a<'a')//0)                 //'a'-'a'would be 0
                a=a-'a'+'z'+1;//+'a';
            //else
            //    a+='a';
        }
        printf("%c",a);
    }
    return 0;
}