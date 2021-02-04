#include <stdio.h>
#include <stdbool.h>
#define n 5

bool visit(char(*)[n], int(*)[n], int, int);
int main(void) {
    char maze[n][n];
    int route[n][n];
    // initialize maze and route matrices
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
	    route[i][j]=0;
	    scanf("%c", &maze[i][j]);
	    getchar();
	}
    }
    if (visit(maze, route, 0, 0)) { // (0,0) is a starting point
        for (int i=0; i<n; i++) {
	    for (int j=0; j<n; j++)
	        printf("%d ", route[i][j]);
	    printf("\n");
        }
    } else {
	printf("Can't find the exit!");
    }
    return 0;
}
// Your code goes here

// TODO: fill the route matrix with 0's or 1‘s.
// If there isn't any route, return false; otherwise, return true.
struct node
{
    int visited;
    int lastX;
    int lastY;
};
struct node node[n][n]={0,0,0};
void go(char maze[][n],int Y,int X);
bool visit(char maze[][n], int route[][n], int X, int Y) 
{
    go(maze,Y,X);
    X=4;
    Y=4;
    if(node[Y][X].visited)
    {
        while(1)
        {
            route[Y][X]=1;
            if(Y==0&&X==0) break;
            int X1,Y1;
            Y1=node[Y][X].lastY;
            X1=node[Y][X].lastX;
            Y=Y1;
            X=X1;
        }
        return 1;
    }
    else return 0;
}
void go(char maze[][n],int Y,int X)
{
    if(node[Y][X].visited) return;
    else node[Y][X].visited=1;
    //right
    if     (X<4 &&maze[Y][X+1]=='r'&&!node[Y][X+1].visited)
    {
        node[Y][X+1].lastX=X;
        node[Y][X+1].lastY=Y;
        go(maze,Y,X+1);
    }
    //down
    if(Y<4 &&maze[Y+1][X]=='r'&&!node[Y+1][X].visited)
    {
        node[Y+1][X].lastX=X;
        node[Y+1][X].lastY=Y;
        go(maze,Y+1,X);
    }
    //left
    if(X>=0&&maze[Y][X-1]=='r'&&!node[Y][X-1].visited)
    {
        node[Y][X-1].lastX=X;
        node[Y][X-1].lastY=Y;
        go(maze,Y,X-1);
    }
    //up
    if(Y>=0&&maze[Y-1][X]=='r'&&!node[Y-1][X].visited)
    {
        node[Y-1][X].lastX=X;
        node[Y-1][X].lastY=Y;
        go(maze,Y-1,X);
    }
    return;
}