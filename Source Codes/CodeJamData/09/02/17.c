#include <stdio.h>
#include <string.h>

#define MAXHW 100
#define MAX_ALTITUDE 10000

const int deltax[4] = {-1, 0, 0, 1};
const int deltay[4] = {0, -1, 1, 0};

int h, w;

int map[MAXHW][MAXHW], mark[MAXHW][MAXHW];

char trans[27];
int basin_count = 0;

void dfs(int x, int y)
{
    int direction, min_value = MAX_ALTITUDE, min_direction;
    for(direction = 0; direction < 4; direction++)
    {
        int xx = x + deltax[direction];
        int yy = y + deltay[direction];
        if(xx < 0 || xx >= h || yy < 0 || yy >= w)continue;
        if(map[xx][yy] < map[x][y] && map[xx][yy] < min_value)
            min_value = map[xx][yy], min_direction = direction;
    }
    if(min_value == MAX_ALTITUDE)
        mark[x][y] = ++basin_count;
    else
    {
        int xx = x + deltax[min_direction];
        int yy = y + deltay[min_direction];
        mark[x][y] = -1;
        if(!mark[xx][yy])dfs(xx, yy);
        mark[x][y] = mark[xx][yy];
    }
}

int main()
{
    int t, testcase;
    scanf("%d", &t);
    for(testcase = 1; testcase <= t; testcase++)
    {
        int i, j;
        memset(mark, 0, sizeof(mark));
        memset(trans, 0, sizeof(trans));
        scanf("%d%d", &h, &w);
        for(i = 0; i < h; i++)
            for(j = 0; j < w; j++)
                scanf("%d", &map[i][j]);
        basin_count = 0;
        for(i = 0; i < h; i++)
            for(j = 0; j < w; j++)
                if(!mark[i][j])dfs(i, j);
        printf("Case #%d:\n", testcase);
        basin_count = 'a';
        for(i = 0; i < h; i++)
        {
            for(j = 0; j < w; j++)
            {
                if(!trans[mark[i][j]])trans[mark[i][j]] = basin_count++;
                printf("%c ", trans[mark[i][j]]);
            }
            putchar('\n');
        }
    }
    return 0;
}
