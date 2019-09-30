#include<stdio.h>
#include<string.h>
char map[51][51];
int next[4][2]={0,1,1,0,0,-1,-1,0},book[51][51],h,w,head,tail,flag;
struct aa
{
    int x,y;
    int step;
}que[2501];
int main()
{
    int i,j,sum=0;
    head=1;
    tail=1;
    que[head].x=1;
    que[head].y=1;
    que[head].step=0;
    tail++;
    book[1][1]=1;
    void bfs(int x,int y);
    scanf("%d%d",&h,&w);
    for(i=1;i<=h;i++)
    {
        getchar();
        for(j=1;j<=w;j++)
        {
            scanf("%c",&map[i][j]);
            if(map[i][j]=='.')
                sum++;
        }
    }
    sum-=1;
    bfs(1,1);
    if(flag==0)
        printf("-1\n");
    else
        printf("%d\n",sum-que[tail-1].step);
    return 0;
}
void bfs(int x,int y)
{
    int i,tx,ty;
    while(head<tail)
    {
        for(i=0;i<4;i++)
        {
            tx=que[head].x+next[i][0];
            ty=que[head].y+next[i][1];
            if(tx<1||tx>h||ty<1||ty>w)
                continue;
            if(map[tx][ty]=='.'&&book[tx][ty]==0)
            {
                que[tail].x=tx;
                que[tail].y=ty;
                que[tail].step=que[head].step+1;
                tail++;
                book[tx][ty]=1;
            }
            if(tx==h&&ty==w)
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
            break;
        head++;
    }
    return;
} ./Main.c: In function ‘main’:
./Main.c:21:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&h,&w);
     ^
./Main.c:27:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%c",&map[i][j]);
             ^