#include <stdio.h>
#include <string.h>

const int dx[4]={0,1,0,-1}, dy[4]={1,0,-1,0};

int check(int x, int y)
{
    return x>=-1000 && x<=1000 && y>=-1000 && y<=1000;
}

int from[2100][2100], step[2100][2100];

void bfs(int tx, int ty)
{
#define QUEUE_SIZE 11000000
    static int queue[QUEUE_SIZE][3];
    static int inqueue[2100][2100];
    int head=-1, tail=0;
    memset(inqueue, 0, sizeof(inqueue));
    memset(from, -1, sizeof(from));
    memset(step, 0, sizeof(step));
    queue[0][0]=0; queue[0][1]=0; queue[0][2]=0;
    inqueue[0+1000][0+1000]=1;
    while(head!=tail) {
        int cx, cy, cs;
        int d;
        cx=queue[head=(head+1)%QUEUE_SIZE][0];
        cy=queue[head][1];
        cs=queue[head][2]+1;
        if(cs>=501) continue;
        for(d=0; d<4; d++) {
            int nx=cx+cs*dx[d], ny=cy+cs*dy[d];
            if(!check(nx, ny)) continue;
            if(inqueue[nx+1000][ny+1000]) continue;
            inqueue[nx+1000][ny+1000]=1;
            queue[tail=(tail+1)%QUEUE_SIZE][0]=nx;
            queue[tail][1]=ny;
            queue[tail][2]=cs;
            from[nx+1000][ny+1000]=d;
            step[nx+1000][ny+1000]=cs;
            if(nx==tx && ny==ty) {
                return;
            }
        }
    }
    fprintf(stderr, "Solution not found for %d, %d\n", tx, ty);
}

void move(int *x, int *y)
{
    int dir=from[*x+1000][*y+1000];
    int st=step[*x+1000][*y+1000];
    *x -= dx[dir]*st;
    *y -= dy[dir]*st;
}

void print_ans(int tx, int ty)
{
    static char ans[1000];
    int anscnt=0;
    static const char letters[4]={'N', 'E', 'S', 'W'}; /* not a string. */
    for(; tx!=0 || ty!=0; 
            ans[anscnt++]=letters[from[tx+1000][ty+1000]],move(&tx, &ty));
    for(anscnt--; anscnt>=0; anscnt--) {
        printf("%c", ans[anscnt]);
    }
    puts("");
}

int main()
{
    int T, Tcnt=0;
    for(scanf("%d", &T); T; T--) {
        int X, Y;
        scanf("%d%d", &X, &Y);
        bfs(X, Y);
        printf("Case #%d: ", ++Tcnt);
        print_ans(X, Y);
    }
    return 0;
}
