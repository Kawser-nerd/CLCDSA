#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(int* a, int* b)
{
    return *a - *b;
}

int main()
{
    int i,j,k;
    int ii,jj,kk;
    int len;
    int split;
    int n, p;
    int ing[100];
    int pack[100][100];
    int cur[100];       
    int tmp[100];       
    int mul;
    int res;

    scanf("%d", &kk);

    for(ii = 1; ii <= kk; ii++)
    {
        memset(cur, 0, 100*sizeof(int));
        memset(tmp, 0, 100*sizeof(int));
        mul = 1;
        res = 0;
        scanf("%d %d", &n, &p);
        for(i = 0; i < n; i++)
            scanf("%d", &ing[i]);

        for(i = 0; i < n; i++)
        {
            for(j = 0; j < p; j++)
            {
                scanf("%d", &pack[i][j]);
            }
        }

        for(i = 0; i < n; i++)
        {
            qsort(pack[i], p, sizeof(int), cmp);
        }
       /* 
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < p; j++)
            {
                printf("%d ", pack[i][j]);
            }
            printf("\n");
        }
        */

        while(1)
        {
            for(i = 0; i < n; i++)
            {
                int gb = 0;
                while(1)
                {
                    if((ing[i] * mul * 11 >= pack[i][cur[i]] * 10) && (ing[i] * mul * 9 <= pack[i][cur[i]] * 10))
                    {
                        //printf("hit %d %d\n", pack[i][cur[i]], ing[i] * mul);
                        break;
                    }
                    else if(ing[i] * mul * 11 < pack[i][cur[i]] * 10)
                    {
                        if(i == 0)
                            mul++;
                        else
                        {
                            gb = 1;
                            mul++;
                            break;
                        }
                    }
                    else if(ing[i] * mul * 9 > pack[i][cur[i]] * 10)
                    {
                        cur[i]++;
                        if(cur[i] == p)
                            break;
                    }
                }
                if(cur[i] == p || gb == 1)
                    break;
            }
            //printf("%d %d %d\n", mul, i, cur[i]);
            if(i < n && cur[i] == p)
                break;
            if(i == n)
            {
                res++;
                for(i = 0; i < n; i++)
                {
                    cur[i]++;
                    if(cur[i] == p)
                        break;
                }
                if(i < n && cur[i] == p)
                    break;
            }
        }
      
        printf("Case #%d: %d\n", ii, res );
    }
}
