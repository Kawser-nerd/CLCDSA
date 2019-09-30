#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int num[21];

int compfunc(const void *p1, const void *p2)
{
    return *(int*)p1 - *(int*)p2;
}

int main()
{
    int i, j, k, T, len;
    int minMax;
    char d;

    scanf("%d\n", &T);

    for (i=1; i<=T; i++)
    {
        d = getchar();
        num[0] = 0;
        j = 1;
        while (d != '\n')
        {
            num[j] = d - '0';
            j++;
            d = getchar();
        }
        len = j;
        k = len-2;
        while (1)
        {
            minMax = -1;
            for (j = len-1; j>k; j--)
            {
                if (num[j] <= num[k])
                    continue;
                if (minMax == -1 || num[j] < num[minMax])
                    minMax = j;
            }
            if (minMax != -1)
            {
                j = num[minMax];
                num[minMax] = num[k];
                num[k] = j;
                qsort(&num[k+1], len - (k+1), sizeof(int), compfunc);
                printf("Case #%d: ", i);
                if (num[0] != 0)
                    printf("%d", num[0]);
                for (j=1; j<len; j++)
                {
                    printf("%d", num[j]);
                }
                printf("\n");
                break;
            }
            k--;
        }
    }
    return 0;
}
