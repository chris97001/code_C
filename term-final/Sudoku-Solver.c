#include <stdio.h>
#include <stdbool.h>

struct element {
    int num;        // 1~9: valid, 0: don't have value yet
    bool can_modify;       // true: white area in the figure, false: gray area in the figure
};

void solve(struct element (*grid_p)[9]);
void print_grid(struct element (*grid_p)[9]) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            printf("%d ", grid_p[i][j].num);
        }
        printf("\n");
    }
}

int main(void) {
    struct element grid[9][9];
    char ch;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            scanf(" %c", &ch);
            if (ch == '.') {    // can_modify assign true, num assign 0
                grid[i][j].num = 0;
                grid[i][j].can_modify = true;
            }
            else {      // value gotten from input, so we can't change this
                grid[i][j].num = ch - '0';
                grid[i][j].can_modify = false;
            }
        }
    }
    solve(grid);
    print_grid(grid);
    return 0;
}
// Your code goes here
int isValid(struct element (*grid_p)[9],int y,int x,int num)
{
    for(int i=0;i<9;i++)
        if(grid_p[y][i].num==num||grid_p[i][x].num==num)
            return 0;//not valid.
    int block_x=(x/3)*3,block_y=(y/3)*3;
    for(int     i=block_x;i<block_x+3;i++)
        for(int j=block_y;j<block_y+3;j++)
            if(grid_p[j][i].num==num)
                return 0;
    return 1;
}

int solve_sudoku(struct element (*grid)[9],int row,int col)
{
    if(col==9)
    {
        col=0;
        row++;
    }
    if(row==9) return 1;//all number is right till the end;
    if(grid[row][col].num) return solve_sudoku(grid,row,col+1);

    for(int num=1;num<=9;num++)
    {
        if(isValid(grid,row,col,num))
        {
            grid[row][col].num=num;         //assume that this number is the answear.
            if(solve_sudoku(grid,row,col+1))
                return 1;                   //means that this number assumption is right.
        }
        grid[row][col].num=0;
    }
    return 0;
}
void solve(struct element (*grid_p)[9])
{
    solve_sudoku(grid_p,0,0);
}