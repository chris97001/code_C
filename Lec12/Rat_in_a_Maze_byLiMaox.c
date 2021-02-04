#include <stdio.h>
#include <stdbool.h>
#define n 5

struct Node{
    int father[2];
    int visited;
};

struct Node node[n][n]={{0,0},0};
bool visit(char(*)[n], int(*)[n], int, int);
void bfs(char (*)[n],int,int);

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
    if (visit(maze, route, 0, 0)) {
        for (int i=0; i<n; i++) {
	    for (int j=0; j<n; j++)
            printf("%d ", route[i][j]);
            //printf("(%d %d) , ", node[i][j].father[0],node[i][j].father[1]);
	    printf("\n");
        }
    } else {
	printf("Can't find the exit!");
    }
    return 0;
}

bool visit(char maze[][n], int route[][n], int originX, int originY){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            node[i][j].father[0]=-1;
            node[i][j].father[1]=-1;
        }
    }
    bfs(maze,0,0);
    int ap=0;
    int x=4,y=4;
    while(1){
        if(x==-1&&y==-1)
            break;
        if(x==0&&y==0)
            ap=1;
        route[y][x]=1;
        int x1,y1;
        x1=node[y][x].father[1];
        y1=node[y][x].father[0];
        x=x1;
        y=y1;
        route[y][x]=1;
    }
    if(ap)
        return 1;
    else
        return 0;
}

void bfs(char maze[][n],int y,int x){
    if(node[y][x].visited) return;
    else node[y][x].visited=1;
    if(maze[y][x+1]=='r'&&x<4&&node[y][x+1].visited==0){
        node[y][x+1].father[0]=y;
        node[y][x+1].father[1]=x;
        bfs(maze,y,x+1);
    }
    if(maze[y][x-1]=='r'&&x>0&&node[y][x-1].visited==0){
        node[y][x-1].father[0]=y;
        node[y][x-1].father[1]=x;
        bfs(maze,y,x-1);
    }
    if(maze[y-1][x]=='r'&&y>0&&node[y-1][x].visited==0){
        node[y-1][x].father[0]=y;
        node[y-1][x].father[1]=x;
        bfs(maze,y-1,x);
    }
    if(maze[y+1][x]=='r'&&y<4&&node[y+1][x].visited==0){
        node[y+1][x].father[0]=y;
        node[y+1][x].father[1]=x;
        bfs(maze,y+1,x);
    }
    return;
}