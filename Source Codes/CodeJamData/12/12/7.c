#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(void* a, void*b)
{
    int* aa;
    int* bb;

    aa = (int*)a;
    bb = (int*)b;

    if(aa[1] < bb[1])
        return -1;
    else if (aa[1] == bb[1])
    {
        return aa[0] - bb[0];
    }
    else
        return 1;
}

int main()
{
    int t, m, n, p,s;
    int i,j,k;
    int nc;
    int result;
    int try;
    int star[2000][2];


    scanf("%d", &t);

    for(nc = 1; nc <= t; nc++)
    {
        scanf("%d", &n);
        for(i = 0; i < n; i++)
        {
            scanf("%d%d", &star[i][0], &star[i][1]);
        }
        qsort(star, n, 2*sizeof(int), cmp);
        result = 0;
        try = 0;

        for(i = 0; i < n; i++)
        {
            if(star[i][1] <= result)
            {
                if(star[i][0] != 9999999)
                    result+=2;
                else
                    result+=1;
                //printf("i:%d j:%d result:%d\n", i, j, result);
                try += 1;
            }
            else
            {
                for(j = n-1; j >=i; j--)
                {
                    if(star[j][0] <= result)
                    {
                        try += 1;
                        result+=1;
                        star[j][0] = 9999999;
                        if(star[i][1] <= result)
                        {
                            try += 1;
                            if(star[i][0] != 9999999)
                                result+=2;
                            else
                                result+=1;

                            j = -10; // break it;
                        }
                        else
                        {
                            j = n;
                        }
                    }
                    //printf("i:%d j:%d result:%d\n", i, j, result);
                }
                if(j > -10)
                {
                    result = -1;
                    i = n;
                }
            }
        }
#if 0
        for(i = 0; i < n; i++)
        {
            printf("%d %d\n", star[i][0], star[i][1]);
        }
#endif
        if(result == -1)
            printf("Case #%d: Too Bad\n",nc);
        else
            printf("Case #%d: %d\n",nc,try);
    }
}
