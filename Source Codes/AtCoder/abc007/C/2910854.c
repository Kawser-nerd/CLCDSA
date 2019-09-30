#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int row,column;
char c[51][51]; 
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
bool reached[50][50];
int qx[3000],qy[3000];
int step[51][51];
int head=0,tail=1;

void bfs(int x,int y);

int main()
{
    int row_start,column_start;
    int row_goal,column_goal;
    scanf("%d%d",&row,&column);
    scanf("%d%d",&row_start,&column_start);
    scanf("%d%d",&row_goal,&column_goal);
    int i;
    for(i=0;i<row;i++){
        scanf("%s",c[i]);
    }

    bfs(row_start-1,column_start-1);
    printf("%d\n",step[row_goal-1][column_goal-1]);

    return 0;
}

void bfs(int x,int y){
    reached[x][y] = true;
    qx[0] = x;
    qy[0] = y;
    step[x][y] = 0;
    int i;
    while( head != tail ){
        // Pop(????)
        int poped_x = qx[head];
        int poped_y = qy[head];
        head++;
        for(i=0;i<4;i++){
            int nx = poped_x + dx[i];
            int ny = poped_y + dy[i];
            // ??????????
            if( ( nx >= 0 ) && ( ny < column ) ){
                // ????????????
                if( (reached[nx][ny] == false) && ( c[nx][ny] == '.' ) ){
                    step[nx][ny] = step[poped_x][poped_y] + 1;
                    reached[nx][ny] = true;
                    qx[tail] = nx;
                    qy[tail] = ny;
                    tail++;
                }
            }
        }
    }
} ./Main.c: In function ‘main’:
./Main.c:22:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&row,&column);
     ^
./Main.c:23:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&row_start,&column_start);
     ^
./Main.c:24:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&row_goal,&column_goal);
     ^
./Main.c:27:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%s",c[i]);
         ^