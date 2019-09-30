#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i,j,k;
    int ii,jj,kk;
    int res;
    int mm;
    int end, xw, ow;
    int n, m, x, y;
    int max;
    int layer;

    double result[1000][1000];
    double prob;

    scanf("%d", &mm);

    for(ii = 1; ii <= mm; ii++)
    {
        memset(result, 0, 1000*1000*sizeof(double));
        scanf("%d%d%d", &n, &x, &y);
        if(x < 0)
            x *= -1;
        if(y < 0)
            y *= -1;

        layer = x + y;

        if( layer * (layer  - 1) / 2 >= n)
            printf("Case #%d: 0.0\n", ii);
        else if( (layer + 2)* (layer  + 1) / 2  <= n)
            printf("Case #%d: 1.0\n", ii);
        else
        {
            int remain = n - (layer * (layer  - 1) / 2);
            if(x == 0)
            {
                if(remain >= layer * 2 + 1)
                    printf("Case #%d: 1.0\n", ii);
                else
                    printf("Case #%d: 0.0\n", ii);
            }
            else
            {
                for(i = 0; i < layer; i++)
                { // gen y prob
                    if(i == 0)
                    {
                        result[1][i] = 0.5;
                        for(j = 2; j <= remain; j++)
                        {
                            if(j <= layer)
                                result[j][i] = result[j-1][i] + (1-result[j-1][i]) * 0.5;
                            else
                                result[j][i] = 1.0;
                        }
                    }
                    else
                    {
                        result[i+1][i] = 0.5;
                        for(j = 1; j < i+1; j++)
                            result[i+1][i] *= 0.5;
                        for(j = i+2; j <= remain; j++)
                        {
                            if(j <= layer + i)
                            {
                                for(k = j - 1; k >= 1; k--) 
                                {
                                    double tmp = result[k][i-1];
                                    for(kk = 0; kk < j - k ; kk++)
                                        tmp *= 0.5;
                                    result[j][i] += tmp;                                
                                }
                            }
                            else
                                result[j][i] = 1.0;
                        }
                    }
                }
#if 0
                for(i = 0; i < layer; i++)
                {
                    for(j = 0; j < 5; j++)
                    {
                        printf("%d %d:%lf\n", i, j, result[j][i]);
                    }
                }
#endif
                printf("Case #%d: %lf\n", ii, result[remain][y]);
            }
        }
    }
}
