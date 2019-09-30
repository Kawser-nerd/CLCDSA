#include <stdio.h>
#include <string.h>

int R, C;
int sy, sx, gy, gx;
char c[60][60];

int head = 0;
int tail = 0;
int que[3000][2];
int dist[60][60];

int dx[] = {0,0,1,-1};
int dy[] = {-1,1,0,0};


void input() {
    int i, j;
    scanf("%d%d%d%d%d%d", &R,&C,&sy,&sx,&gy,&gx);
    sy--; sx--; gy--; gx--;
    for(i=0; i<R; ++i) {
       scanf("%s", c[i]);
    }
}

int main() {
    input();
    int i, j;
    for(i=0; i<R; ++i) {
        for(j=0; j<C; ++j) {
            dist[i][j] = 1<<29;
        }
    }
    dist[sy][sx] = 0;
    que[0][0] = sy;
    que[0][1] = sx;
    tail = 1;
    while(head != tail) {
        int ny, nx;
        ny = que[head][0];
        nx = que[head][1];
        head = (head + 1) % 3000;
        for(i=0; i<4; ++i) {
            int ay = ny + dy[i];
            int ax = nx + dx[i];
            if(ay>=0&&ay<R&&ax>=0&&ax<C&&c[ay][ax]=='.'&&dist[ay][ax] > dist[ny][nx]+1) {
                dist[ay][ax] = dist[ny][nx] + 1;
                que[tail][0] = ay;
                que[tail][1] = ax;
                tail = (tail+1)%3000;
            }
        }
    }
    printf("%d\n", dist[gy][gx]);
} ./Main.c: In function ‘input’:
./Main.c:19:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d%d%d%d", &R,&C,&sy,&sx,&gy,&gx);
     ^
./Main.c:22:8: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
        scanf("%s", c[i]);
        ^