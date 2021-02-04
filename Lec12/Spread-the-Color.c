#include <stdio.h>
#define M 5
#define N 8
char colors[4] = {'R', 'G', 'B', 'X'};   // Red, Green, Blue, Empty

void spread(char*, int, int);

int main(void) {
    char graph[M][N];
    int row, col;

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++)
            scanf("%c", &graph[i][j]);
        getchar();      // Ignore '\n'
    }
    scanf("%d %d", &row, &col);    // Starting position
    
    spread(&graph[0][0], row, col);
    
    // Print out the spreading result
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++)
            printf("%c", graph[i][j]);
        printf("\n");
    }
    return 0;
}
// Your code goes here
void spread(char *graph, int row, int col) 
{
    char color=*(graph+row*8+col);
    //up
    for(int i=row;i>=0;i--)
    {
        if(*(graph+i*8+col)=='X'||*(graph+i*8+col)==color)
            *(graph+i*8+col)=color;
        else break;
    }
    //down
    for(int i=row;i<M;i++)
    {
        if(*(graph+i*8+col)=='X'||*(graph+i*8+col)==color)
            *(graph+i*8+col)=color;
        else break;
    }
    //left
    for(int i=col;i>=0;i--)
    {
        if(*(graph+row*8+i)=='X'||*(graph+row*8+i)==color)
            *(graph+row*8+i)=color;
        else break;
    }
    //right
    for(int i=col;i<N;i++)
    {
        if(*(graph+row*8+i)=='X'||*(graph+row*8+i)==color)
            *(graph+row*8+i)=color;
        else break;
    }
}
