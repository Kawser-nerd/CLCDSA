#include <stdio.h>

#define NMAX   100
#define HMAN    50
#define WSPEED  10.0
#define HSLOW   20
#define FAST     1
#define SLOW    10

#define INF (1./0.)

#define checkmove(i1,j1,i2,j2) (time[i2][j2] > timenow && access[i2][j2] != INF && ceil[i1][j1] >= floor[i2][j2] + HMAN && ceil[i2][j2] >= floor[i1][j1] + HMAN)

int main()
{
    int t, c;
    int h, n, m;
    int floor[NMAX][NMAX], ceil[NMAX][NMAX];
    double access[NMAX][NMAX], slow[NMAX][NMAX];
    double time[NMAX][NMAX];
    double timenow, timenext;
    int i, j, change;
    
    scanf("%d", &t);
    for (c = 1; c <= t; c++)
    {
        scanf("%d%d%d", &h, &n, &m);
        for (i=0; i<n; i++) for (j=0; j<m; j++)
            scanf("%d", &ceil[i][j]);
        for (i=0; i<n; i++) for (j=0; j<m; j++)
        {
            scanf("%d", &floor[i][j]);
            if (floor[i][j] + HMAN > ceil[i][j])
            {
                access[i][j] = slow[i][j] = INF;
            }
            else
            {
                if (ceil[i][j] < h + HMAN)
                    access[i][j] = (h + HMAN - ceil[i][j]) / WSPEED;
                else
                    access[i][j] = 0.0;
                if (floor[i][j] < h - HSLOW)
                    slow[i][j] = (h - HSLOW - floor[i][j]) / WSPEED;
                else
                    slow[i][j] = 0.0;
            }
            time[i][j] = INF;
        }
        
        time[0][0] = 0;
        timenow = 0;
        change = 1;
        while (change)
        {
            change = 0;
            for (i=0; i<n; i++) for (j=0; j<m; j++)
                if (time[i][j] == 0)
                {
                    if (i>0 && checkmove(i, j, i-1, j) && access[i-1][j] == 0)
                    {
                        time[i-1][j] = 0;
                        change = 1;
                    }
                    if (j>0 && checkmove(i, j, i, j-1) && access[i][j-1] == 0)
                    {
                        time[i][j-1] = 0;
                        change = 1;
                    }
                    if (i<n-1 && checkmove(i, j, i+1, j) && access[i+1][j] == 0)
                    {
                        time[i+1][j] = 0;
                        change = 1;
                    }
                    if (j<m-1 && checkmove(i, j, i, j+1) && access[i][j+1] == 0)
                    {
                        time[i][j+1] = 0;
                        change = 1;
                    }
                }
        }
        while (timenow != INF)
        {
            for (i=0; i<n; i++) for (j=0; j<m; j++)
                if (time[i][j] == timenow)
                {
                    if (i>0 && checkmove(i, j, i-1, j))
                    {
                        timenext = timenow;
                        if (timenext < access[i-1][j])
                            timenext = access[i-1][j];
                        if (timenext <= slow[i][j])
                            timenext += FAST;
                        else
                            timenext += SLOW;
                        if (time[i-1][j] > timenext)
                            time[i-1][j] = timenext;
                    }
                    if (j>0 && checkmove(i, j, i, j-1))
                    {
                        timenext = timenow;
                        if (timenext < access[i][j-1])
                            timenext = access[i][j-1];
                        if (timenext <= slow[i][j])
                            timenext += FAST;
                        else
                            timenext += SLOW;
                        if (time[i][j-1] > timenext)
                            time[i][j-1] = timenext;
                    }
                    if (i<n-1 && checkmove(i, j, i+1, j))
                    {
                        timenext = timenow;
                        if (timenext < access[i+1][j])
                            timenext = access[i+1][j];
                        if (timenext <= slow[i][j])
                            timenext += FAST;
                        else
                            timenext += SLOW;
                        if (time[i+1][j] > timenext)
                            time[i+1][j] = timenext;
                    }
                    if (j<m-1 && checkmove(i, j, i, j+1))
                    {
                        timenext = timenow;
                        if (timenext < access[i][j+1])
                            timenext = access[i][j+1];
                        if (timenext <= slow[i][j])
                            timenext += FAST;
                        else
                            timenext += SLOW;
                        if (time[i][j+1] > timenext)
                            time[i][j+1] = timenext;
                    }
                }
            timenext = INF;
            for (i=0; i<n; i++) for (j=0; j<m; j++)
                if (time[i][j] > timenow && time[i][j] < timenext)
                    timenext = time[i][j];
            timenow = timenext;
        }
        
        printf("Case #%d: %f\n", c, time[n-1][m-1]);
    }
    return 0;
}
