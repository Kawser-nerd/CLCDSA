#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
char map[150][150];
char room[50][50];
int xpos,ypos;
int h,w,d;
int shang,xia,zuo,you;
int func(int a,int b)
{
    int temp;
    if(a==0 &&b)return b;
    if(b==0 &&a)return a;
    while(b)
    {
        temp = a%b;
        a = b;
        b = temp;
    }
    return a;
}
int check(int a,int b,int x_pos,int y_pos)
{

    int temp = func(max(abs(a),abs(b)), min(abs(a),abs(b)) );
    int i = a,j = b,k;
    i /= temp;
    j /= temp;
    k = temp - 1;
    while(k > 0)
    {
        if(map[i*k+x_pos][j*k+y_pos])
        {
            return 0;
        }
        k--;
    }
    return 1;
}
typedef struct
{
    int x,y;
}POS;
POS que[100000];
int front,back;
int update()
{
    int i,j,cons = 0;
    POS temp;
    while(front<back)
    {
        i = que[front].x;
        j = que[front].y;
        front++;
        if(map[i][j])continue;
        map[i][j] = 1;
        if(j > zuo && j <= d+ypos)
        {
            temp.x = i;
            temp.y = 2*zuo-j+1;
            que[back++] = temp;
        }
        if(j < you && j >= ypos-d)
        {
            temp.x = i;
            temp.y = 2*you-j-1;
            que[back++] = temp;
        }
        if(i > shang && i <= xpos+d)
        {
            temp.x = 2*shang-i+1;
            temp.y = j;
            que[back++] = temp;
        }
        if(i < xia && i >= xpos-d)
        {
            temp.x = 2*xia-i-1;
            temp.y = j;
            que[back++] = temp;
        }
    }
    for(i = -1*d; i <= d; i++)
    {
            for(j = -1*d; j <= d; j++)
            {
                if(i==0&&j==0)continue;
                if(map[i+xpos][j+ypos] && i*i+j*j <= d*d)
                {
                    cons += check(i,j,xpos,ypos);
                }
            }

    }
    return cons;
}
int main()
{
    freopen("out.txt","w",stdout);
    freopen("D-small-attempt0.in","r",stdin);
    int i,j,t,n;
    POS temp;
    int cons;
    scanf("%d", &t);
    for(n = 1; n <= t; n++)
    {
        scanf("%d%d%d%*c", &h,&w,&d);
        memset(map,0,sizeof(map));
        front = 0;back = 0;
        for(i = 0; i < h; i++)scanf("%s",room[i]);
        for(i = 0; i < h; i++)
        {
            for(j = 0; j < w; j++)
            {
                if(room[i][j] == 'X')
                {
                    xpos = i + 70;
                    shang = xpos - i;
                    xia = shang + h -1;
                    ypos = j + 70;
                    zuo = ypos - j;
                    you = zuo + w -1;
                    temp.x = xpos;
                    temp.y = ypos;
                    que[back++] = temp;
                    goto next1;
                }
            }
        }
        next1:
        cons = update();
        printf("Case #%d: %d\n",n,cons);
    }
    return 0;
}
