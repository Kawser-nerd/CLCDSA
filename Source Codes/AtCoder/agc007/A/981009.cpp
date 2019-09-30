#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char grid[9][9];

int main()
{
    int h,w,x,y,t,flag;
    while(~scanf("%d%d",&h,&w))
    {
        flag=0;
        memset(grid,0,sizeof(grid));
        scanf("%*c");
        for(x=0;x<h;x++)
        {
            for(y=0;y<w;y++)
            {
                scanf("%c",&grid[x][y]);
            }
            scanf("%*c");
        }
        x=y=0;
        while((x!=h-1||y!=w-1)&&!flag)
        {
            if(grid[x][y]=='#')
            {
            if(grid[x][y+1]=='#')
            {
                y++;
            }
            else
            {
                x++;
                if(x<h&&y<w)
                {
                    for(t=y+1;t<=w-1;t++)
                    {
                            if(grid[x-1][t]=='#')
                            {flag=1;break;}
                    }
                    for(t=0;t<y;t++){if(grid[x][t]=='#'){flag=1;break;}}
                }
            }
            }
            else
                flag=1;
        }
        if(grid[h-1][w-1]=='.')
            flag=1;
        if(!flag)
            printf("Possible\n");
        else
            printf("Impossible\n");
    }
    return 0;
}