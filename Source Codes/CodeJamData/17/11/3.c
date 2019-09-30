#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i,j,k;
    int ii,jj,kk;
    int now;
    int max;
    int res;
    int len;
    int count=0;
    char map[50][50];
    int r, c;

    scanf("%d", &kk);

    for(ii = 1; ii <= kk; ii++)
    {
        scanf("%d %d", &r, &c);

        for(i = 0; i < r; i++)
        {
            scanf("%s", map[i]);
        }

        int backfill = 0;
        char first;
        for(i = 0; i < r; i++)
        {
            for(j = 0; j < c; j++)
            {
                if(map[i][j] != '?')
                {
                    first = map[i][j];
                    break;
                }
            }
            if(j == c)
            {
                if(i == 0 || backfill == 1)
                {
                    backfill = 1;
                    continue;
                }
                else
                {
                    memcpy(map[i], map[i-1], c);
                    continue;
                }
            }
            for(j = 0; j < c; j++)
            {
                if(map[i][j] == '?')
                {
                    map[i][j] = first;
                }
                else
                {
                    first = map[i][j];
                }
            }
            if(backfill == 1)
            {
                for(k = 0; k < i; k++)
                {
                    memcpy(map[k], map[i], c);
                }
                backfill =0;
            }
        }

        printf("Case #%d:\n", ii);
        for(i = 0; i < r; i++)
        {
            printf("%s\n", map[i]);
        }

    }
}
