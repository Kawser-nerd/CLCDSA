#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i, j, k, t, r, xmax, ymax;

char map[100][100];

int main()
{
    int ii, jj, kk, bad, sec;
    scanf("%d", &t);

    for(i = 1; i <=t ; i++)
    {
        xmax = 0;
        ymax = 0;
        sec = 0;
        memset(map, 0, sizeof(char) * 100 * 100);
        scanf("%d", &r);
        for(ii = 0; ii < r; ii++)
        {
            int x1,x2,y1,y2;
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            
            if(x1 > xmax)
                xmax = x1;
            if(x2 > xmax)
                xmax = x2;
            if(y1 > ymax)
                ymax = y1;
            if(y2 > ymax)
                ymax = y2;
            for(jj = x1; jj <= x2; jj++)
            {
                for(kk = y1; kk <= y2; kk++)
                {
                    map[jj-1][kk-1] = 1;
                }
            }
        }
        while(1)
        {
            bad = 0;
            for(ii = 0; ii < xmax; ii++)
            {
                for(jj = 0; jj < ymax; jj++)
                {
                    if(map[ii][jj] == 1)
                    {
                        bad = 1;
                        break;
                    }
                }
                if(bad == 1)
                    break;
            }
            if(bad == 0)
                break;

            sec++;
            for( ii = xmax-1; ii >= 0; ii--)
            {
                for(jj = ymax -1; jj >= 0; jj--)
                {
                    if(ii == 0 || jj == 0)
                        map[ii][jj] = 0;
                    else
                    {
                        if(map[ii-1][jj] == 0 && map[ii][jj-1] == 0)
                            map[ii][jj] = 0;
                        else if(map[ii-1][jj] == 1 && map[ii][jj-1] == 1)
                            map[ii][jj] = 1;
                    }
                }
            }
        }

        printf("Case #%d: %d\n", i, sec);
    }
}
