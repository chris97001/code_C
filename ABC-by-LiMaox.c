#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void swap(char a[],int i,int j){
    char temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}

void sort(char a[],int start,int n){
    if(start>=n){
        printf("%s\n",a);
        return ;
    }
    for(int i=start;i<n;i++){
        char b[n];
        strcpy(b,a);
        swap(b,i,start);
        for(int j=start+1;j<n;j++)
            for(int k=j+1;k<n;k++)
                if(b[k]<b[j]) swap(b,j,k);

        sort(b,start+1,n);
    }
    return ;
}

int main(){
    char a[6];
    scanf("%s",a);
    for(int i=0;i<strlen(a);i++){
        for(int j=i+1;j<strlen(a);j++){
            if(a[j]<a[i]) swap(a,i,j);
        }
    }
    sort(a,0,strlen(a));
    return 0;
}