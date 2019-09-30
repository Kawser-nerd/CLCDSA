#include <stdio.h>

int n, m;
int s[20][20], w[20][20], f[20][20], f2[20][20], cyc[20][20];
long long dist[40][40];
int used[40][40];

long long next (int x1, int y1, int x2, int y2)
{
    long long d = dist[x1][y1];
    
    if (x1 / 2 == x2 / 2 && y1 / 2 == y2 / 2)
    {
        if (x1 == x2)
        {
            //East - West
            long long nextd;
            nextd = (d + cyc[x1/2][y1/2] - 1 - f2[x1/2][y1/2]) / cyc[x1/2][y1/2] * cyc[x1/2][y1/2] + f2[x1/2][y1/2];
            if (nextd - cyc[x1/2][y1/2] + w[x1/2][y1/2] > d)
                nextd = d;
//            printf("%d %d -> %d %d at %I64d: %I64d\n", x1, y1, x2, y2, d, nextd + 1);
            
            return nextd + 1;
        }
        else
        {
            //North - South
            long long nextd;
            nextd = (d + cyc[x1/2][y1/2] - 1 - f[x1/2][y1/2]) / cyc[x1/2][y1/2] * cyc[x1/2][y1/2] + f[x1/2][y1/2];
            if (nextd - cyc[x1/2][y1/2] + s[x1/2][y1/2] > d)
                nextd = d;

//            printf("%d %d -> %d %d at %I64d: %I64d\n", x1, y1, x2, y2, d, nextd + 1);

            return nextd + 1;
        }
    }
    else
    {
//        printf("%d %d -> %d %d at %I64d: %I64d\n", x1, y1, x2, y2, d, d + 2);
        return d + 2;
    }
}

int main ()
{
    int t, ct = 0;
    
    for (scanf("%d", &t); t > 0; t --)
    {
        scanf("%d%d", &n, &m);
        
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < m; j ++)
            {
                scanf("%d%d%d", s[i] + j, w[i] + j, f[i] + j);
                cyc[i][j] = s[i][j] + w[i][j];
                f[i][j] %= cyc[i][j];
                f2[i][j] = (f[i][j] + s[i][j]) % cyc[i][j];
            }
        
        for (int i = 0; i < n + n; i ++)
            for (int j = 0; j < m + m; j ++)
            {
                used[i][j] = 0;
                dist[i][j] = 100000000000000000LL;
            }
        dist[n + n - 1][0] = 0;
        
        long long tmp;
        
        for (int kk = 0; kk < n * m * 4; kk ++)
        {
            long long best = 100000000000000000LL;
            int bi, bj;
            
            for (int i = 0; i < n + n; i ++)
                for (int j = 0; j < m + m; j ++)
                    if (used[i][j] == 0 && dist[i][j] < best)
                    {
                        best = dist[i][j];
                        bi = i;
                        bj = j;
                    }
//            printf("bi bj %d %d\n", bi, bj);
            used[bi][bj] = 1;
            
            if (bi - 1 >= 0 && (tmp = next(bi, bj, bi - 1, bj)) < dist[bi - 1][bj])
            {
                dist[bi - 1][bj] = tmp;
            }
            if (bj - 1 >= 0 && (tmp = next(bi, bj, bi, bj - 1)) < dist[bi][bj - 1])
            {
                dist[bi][bj - 1] = tmp;
            }
            if (bi + 1 < n + n && (tmp = next(bi, bj, bi + 1, bj)) < dist[bi + 1][bj])
            {
                dist[bi + 1][bj] = tmp;
            }
            if (bj + 1 < m + m && (tmp = next(bi, bj, bi, bj + 1)) < dist[bi][bj + 1])
            {
                dist[bi][bj + 1] = tmp;
            }
        }
        
        printf("Case #%d: %I64d\n", ++ct, dist[0][m + m - 1]);
    }
}
