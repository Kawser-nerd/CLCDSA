#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int price[10][1024];
int buy[10][1024];
int m[2048];
int tempm[2048];
int i, j, k, t, p;
int dp[10][1024][10];

#define MAX 2000000000

int check()
{
    int ii, jj, kk;
   
    for(ii = 0; ii < (1 << p); ii++)
    {
        if(m[ii] < p)
            return ii;
    }
    return -1;
}

unsigned int go(int a, int b, int c)
{
    int ii, jj, kk;
    unsigned int min;
    int need;

    if(dp[a][b][c] != -1)
        return dp[a][b][c];

    if(a == 0)
    {
        need = 0;
        for(ii = b * (1 << (a + 1)); ii < (b+1) * (1 << (a+1)) ;ii++)
        {
            if(m[ii] + c == (p - 1))
            {
                need = 1;
            }
            if ( m[ii] + c < (p - 1))
            {
                need = -1;
                break;
            }
        }
        //printf("a=%d b=%d c=%d, need=%d\n", a,b,c,need);
        if(need == 1)
            dp[a][b][c] = price[a][b];
        else if(need == -1)
            dp[a][b][c] = MAX;
        else
            dp[a][b][c] = 0;
        return dp[a][b][c];
    }
    else
    {
        unsigned int temp;
        unsigned int temp2;
        min = MAX;

        temp2 = 0;
        for(ii = 0; ii < 2; ii++)
        {
            temp = go(a-1, b*2+ii, c);
            if(temp == MAX) 
            {
                break;
            }
            else
            {
                temp2 += temp;
            }
        }
        if(ii == 2 && temp2 < min)
            min = temp2;

        temp2 = 0;
        for(ii = 0; ii < 2; ii++)
        {
            temp = go(a-1, b*2+ii, c+1);
            if(temp == MAX) 
            {
                break;
            }
            else
            {
                temp2 += temp;
            }
        }
        if(ii == 2 && temp2 + price[a][b] < min)
            min = temp2 + price[a][b];

        dp[a][b][c] = min;
        return dp[a][b][c];
    }
}

int main()
{
    int ii, jj, kk;
    unsigned int res;
    unsigned int tp;

    scanf("%d", &t);

    for(i = 1; i <= t; i++)
    {
        scanf("%d", &p);

        memset(buy, 0, sizeof(int) * 10 * 1024);
        memset(dp, -1, sizeof(int) * 10 * 1024 * 10);
        for(ii = 0; ii < (1 << p); ii++)
        {
            scanf("%d", &m[ii]);
        }
        for(ii = 0; ii < p; ii++)
        {
            for(jj = 0; jj < (1<<(p-ii-1)); jj++)
            {
                scanf("%d", &price[ii][jj]);
            }
        }
        printf("Case #%d: %d\n", i, go(p-1, 0, 0));

#if 0
        for(ii = 0; ii < p ; ii++)
        {
            for(kk = 0; kk < p; kk++)
            {
                for(jj = 0; jj < (1 << (p-1)); jj++)
                {
                    printf("%d ", dp[kk][jj][ii]);
                }
                printf("\n");
            }
            printf("\n");
        }
        res = 4000000000;
        for(ii = 0; ii <= min; ii++)
        {
            tp = 0;
            memcpy(tempm, m, 2048 * sizeof(int));

            for(jj = 0; jj < (1 << ii        while(1)
        {
            int target = check();
            if(target < 0)
                break;
            res++;
            ii = p -1;
            while(1)
            {
                if(buy[ii][target >> (ii+1)] == 0)
                    break;
                ii--;
            }
            buy[ii][target >> (ii+1)] = 1;
            for(jj = 0; jj < (1 << p); jj++)
            {
                if( jj >> (ii+1) == target >> (ii+1))
                    m[jj]++;
            }
        }
); jj++)
            {
                for(kk = (1 << p - jj); kk < (1 << (p-jj+1)) ; kk++)
                {
                    if(tempm[kk] < p)
                        break;
                }
                int tmax = 1 << (p - jj) 
                if(kk < (1 << ( p -jj + 1)))
                {
                    tp += price[p-ii-1][jj];
                    for(kk = (1 << p - jj); kk < (1 << (p-jj+1)) ; kk++)
                    {
                        tempm[kk]++;
                    }
                }
                
            }


            while(1)
            {
                int target = check();
                if(target < 0)
                    break;
                res++;
                ii = p -1;
                while(1)
                {
                    if(buy[ii][target >> (ii+1)] == 0)
                        break;
                    ii--;
                }
                buy[ii][target >> (ii+1)] = 1;
                for(jj = 0; jj < (1 << p); jj++)
                {
                    if( jj >> (ii+1) == target >> (ii+1))
                        m[jj]++;
                }
            }

        }
        while(1)
        {
            int target = check();
            if(target < 0)
                break;
            res++;
            ii = p -1;
            while(1)
            {
                if(buy[ii][target >> (ii+1)] == 0)
                    break;
                ii--;
            }
            buy[ii][target >> (ii+1)] = 1;
            for(jj = 0; jj < (1 << p); jj++)
            {
                if( jj >> (ii+1) == target >> (ii+1))
                    m[jj]++;
            }
        }
#endif
    }
}
