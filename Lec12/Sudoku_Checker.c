#include <stdio.h>
#define NUM 9

void check_sudoku(int (*grid_p)[NUM]);

int main(void){
    int grid[NUM][NUM]; // sudoku puzzle
    for(int i = 0; i < NUM; ++i){
        for(int j = 0; j < NUM; ++j){
            scanf("%d", &grid[i][j]);
        }
    }
    check_sudoku(grid);
    return 0;
}
// Your code goes here

void check_sudoku(int (*grid_p)[NUM])
{
    int exist[NUM][NUM]={};
        for(int i=0;i<NUM;i++)
        {
            for(int j=0;j<NUM;j++)
            {
                //col
                for(int j1=0;j1<NUM;j1++)
                    if(grid_p[i][j]==grid_p[i][j1]&&j1!=j)
                    {
                        exist[i][j]=1;
                        exist[i][j1]=1;
                    }
                //row
                for(int i1=0;i1<NUM;i1++)
                {
                    if(grid_p[i][j]==grid_p[i1][j]&&i1!=i)
                    {
                        exist[i][j]=1;
                        exist[i1][j]=1;
                    }
                }
                //9x9
                int block_row,block_col;//decide which 9x9 block should i1,j1 start
                if(i<3)         block_row=0;
                else if(i<6)    block_row=1;
                else            block_row=2;
                if(j<3)         block_col=0;
                else if (j<6)   block_col=1;
                else            block_col=2;
                for(int i1=block_row*3;i1<(block_row+1)*3;i1++)
                    for(int j1=block_col*3;j1<(block_col+1)*3;j1++)
                        if(grid_p[i][j]==grid_p[i1][j1]&&i!=i1&&j!=j1)
                        {
                            exist[i][j]=1;
                            exist[i1][j1]=1;
                        }
            }
        }
    //print
    for(int i1=0;i1<NUM;i1++)
        for(int j1=0;j1<NUM;j1++)
        {
            if(exist[i1][j1]==1)
            printf("(%d,%d)\n",i1,j1);    
        }  
}