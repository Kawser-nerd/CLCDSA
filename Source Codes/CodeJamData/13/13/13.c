#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i,j;
    int ii,jj,kk;
    int res;
    int mm;
    int end, xw, ow;
    int r, n, m, k;
    int max;
    unsigned int v[20];
    unsigned int factor[20][10];

    unsigned long long result;

    scanf("%d", &mm);

    for(ii = 1; ii <= mm; ii++)
    {
        scanf("%d%d%d%d", &r, &n, &m, &k);
        printf("Case #1:\n");

        for(jj = 0; jj < r; jj++)
        {
            memset(factor, 0, sizeof(factor));
            for(i = 0; i < k; i++)
            {
                scanf("%d", &v[i]);

                if(v[i] > 1)
                {
                    for(j = 2; j <= m; j++)
                    {
                        int temp = v[i];
                        while(temp % j == 0)
                        {
                            factor[i][j]++;
                            temp /= j;
                        }
                    }
                }
            }
    
            for(i = 0; i < k; i++)
            {
                int count = 0;
                for(j = 3; j <= m; j++)
                {
                    if(factor[i][j] > 0)
                        count += factor[i][j];
                }
                if(count >= n)
                {
                    for(j = 3; j <= m; j++)
                    {
                        for(kk = 0; kk < factor[i][j] ; kk++)
                            printf("%d", j);
                    }

                    printf("\n");
                    break;
                }
            }
            if(i == k)
            { // no perfect
                kk = 0;
                for(j = m; j>=2; j--)
                {
                    int max = 0;
                    for(i = 0; i < k; i++)
                    {
                        if(factor[i][j] > max)
                            max = factor[i][j];
                    }
                    for(i = 0; i < max && kk < n; i++)
                    {
                        printf("%d", j);
                        kk++;
                    }
                }
                if(kk < n)
                for(i = kk; i < n; i++)
                    printf("2");

                printf("\n");
            }
        }
    }
}
