#include <stdio.h>
#include <stdlib.h>
#define n 8000

// Ignore this
void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*)){exit(1);}
// Ignore this

void quicksort(int a[], int low, int high);
int main(void) {
  int a[n];
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);
  quicksort(a, 0, n - 1);
  for (int i = 0; i < n; i++)
    printf("%d ", a[i]);
  return 0;
}

// Your code goes here
int split(int a[],int s_low,int s_high)
{
    int temp=a[s_low];
    while(1)
    {
        while(s_low<s_high&&temp<=a[s_high])5 4 3 2 1
            s_high--;
        if(s_low>=s_high) 
            break;
        a[s_low++]=a[s_high];
        while(s_low<s_high&&temp>=a[s_low])
            s_low++;
        if(s_low>=s_high) 
            break;
        a[s_high--]=a[s_low];
    }
    a[s_high]=temp;
    return s_high;
}
void quicksort(int a[], int low, int high) 
{
    int middle;
    if(low>=high) 
        return;
    middle=split(a,low,high);
    quicksort(a,low,middle-1);
    quicksort(a,middle+1,high);
}
/*
void quicksort(int a[], int low, int high) 
{
    int middle;
    if(low>=high) 
        return;
    int temp=a[low];
    int s_low=low,s_high=high;
    while(1)
    {
        while(s_low<s_high&&temp<=a[s_high])
            s_high--;
        if(s_low>=s_high) 
            break;
        a[s_low]=a[s_high];
      	s_low++;
        while(s_low<s_high&&temp>=a[s_low])
            s_low++;
        if(s_low>=s_high) 
            break;
        a[s_high]=a[s_low];
        s_high--;
    }
    a[s_high]=temp;
    middle=s_high;
    quicksort(a,low,middle-1);
    quicksort(a,middle+1,high);
}*/

