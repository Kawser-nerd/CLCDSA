#include <stdio.h>
 
int R, C, head = 0, tail = 0, que[2500][2], dis[50][50];
int sy, sx, gy, gx;
char s[50][51];
 
int dx[] = {0,0,1,-1};
int dy[] = {-1,1,0,0};
 
int main() {
	int i, j, ny, nx, wy, wx;
 
    scanf("%d %d", &R, &C);
    scanf("%d %d", &sy, &sx);
    scanf("%d %d", &gy, &gx);
    for(i=0; i<R; ++i) {
       scanf("%s", s[i]);
    }
    
    sy--;
    sx--;
    gy--;
    gx--;
 
    for(i=0; i<R; ++i) {
        for(j=0; j<C; ++j) {
            dis[i][j] = -1;
        }
    }
    dis[sy][sx] = 0;
    que[0][0] = sy;
    que[0][1] = sx;
    tail = 1;
    while(head != tail) {
        ny = que[head][0];
        nx = que[head][1];
        head = (head + 1) % 2500;
        for(i=0; i<4; ++i) {
            wy = ny + dy[i];
            wx = nx + dx[i];
            if(wy >= 0 && wy < R && wx >= 0 && wx < C && s[wy][wx] == '.' && dis[wy][wx] < 0) {
                dis[wy][wx] = dis[ny][nx] + 1;
                que[tail][0] = wy;
                que[tail][1] = wx;
                tail = (tail+1)%2500;
            }
        }
    }
 
    printf("%d\n", dis[gy][gx]);
 
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &R, &C);
     ^
./Main.c:14:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &sy, &sx);
     ^
./Main.c:15:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &gy, &gx);
     ^
./Main.c:17:8: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
        scanf("%s", s[i]);
        ^