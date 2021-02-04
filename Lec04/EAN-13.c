#include<stdio.h>

int main(){
    /*int i1,i2,i3,i4,i5,i6,i7,i8,i9,i10,i11,i12;
    scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d",&i12,&i11,&i10,&i9,&i8,&i7,&i6,&i5,&i4,&i3,&i2,&i1);
    int sum=(i1+i3+i5+i7+i9+i11)*3+(i2+i4+i6+i8+i10+i12)*1;
    int nearest=(sum-1)/10*10+10;
    int checkdigit=nearest-sum;
    printf("%d",checkdigit);
    */
    char str[12]={0};
    scanf("%s %s %s",&str[0],&str[1],&str[7]);
    int even=0,odd=0;
    for(int i=0;i<12;i++){
        even+=(str[i]-48)*(i&1^1);
        odd+=(str[i]-48)*(i&1);
    }
    odd*=3;
    int sum=(odd+even)%10;
    return 0;
}
