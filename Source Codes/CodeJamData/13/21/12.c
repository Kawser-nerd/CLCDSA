#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(int* a, int* b)
{
    return *a - *b;
}

int main()
{
    int i,j;
    int ii,jj,kk;
    int res;
    int mm;
    int end, xw, ow;
    int n, m, a;
    int max;
    int moles[200];
    int result = 0;
    int asize = 0;

    scanf("%d", &mm);

    for(ii = 1; ii <= mm; ii++)
    {
        result = 0;
        asize = 0;
        scanf("%d%d", &a, &n);

        for( i = 0; i < n; i++)
            scanf("%d", &moles[i]);

        qsort(moles, n, sizeof(int), cmp);

        asize = a;
        for(i = 0; i < n ; i++)
        {
            //printf("m:%d asize:%d\n", moles[i], asize);
            if(moles[i] >= asize)
            {
                int tmpcnt = 0;
                int tmpsize = asize;
                if(tmpsize - 1 > 0)
                {
                    while(moles[i] >= tmpsize)
                    {
                        tmpsize += tmpsize - 1;
                        tmpcnt++;
                    }
                    if(tmpcnt < n - i)
                    {
                        result += tmpcnt;
                        asize = tmpsize + moles[i];
                    }
                    else
                    {
                        result++;
                    }
                }
                else
                {
                    result++;
                }
            }
            else
            {
                asize += moles[i];
            }
        }
        if(result > n)
            result = n;

        printf("Case #%d: %d\n", ii, result);
    }
}
