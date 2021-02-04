#include<stdio.h>
int main()
{
    int stageN;
    scanf("%d",&stageN);
    for(int stage_i=1;stage_i<=stageN;stage_i++)
    {
        for(int space_num=1;space_num<=(stageN-stage_i);space_num++)
        	printf(" ");
        for(int block_num=1;block_num<=stage_i*2-1;block_num++)
        	printf("*");
        printf("\n");
    }

    return 0;
}