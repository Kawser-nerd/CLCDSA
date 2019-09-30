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
    int now;
    int max;
    int res;
    int len;
    int count=0;
    int group[200];
    int n, p, tmp, c1, c2, c3;

    scanf("%d", &kk);

    for(ii = 1; ii <= kk; ii++)
    {
        res = 0;
        tmp = 0;
        c1 = 0;
        c2 = 0;
        c3 = 0;
        scanf("%d %d", &n, &p);

        for(i = 0; i < n; i++)
        {
            scanf("%d", &group[i]);
            group[i] = group[i] % p;
        }

        qsort(group, n, sizeof(int), cmp);

        i = 0;
        j = n -1;
        for(i = 0; i < n; i++)
        {
            if(group[i] == 0)
                res++;
            if(group[i] == 1)
                c1++;
            if(group[i] == 2)
                c2++;
            if(group[i] == 3)
                c3++;
#if 0
            else
            {
                if(i != j && group[i] + group[j] == p)
                {
                    res++;
                    if(j - i <= 2)
                    {
                        if(j - i == 2)
                            res++;
                        
                        break;
                    }
                    j--;
                }
                else
                {
                    if(tmp == 0)
                        res++;
                    tmp = (tmp + group[i]) % p;
                }
            }
#endif
        }
        //printf("%d %d %d\n", res, c1, c2);
        if(p == 2)
        {
            res += (c1 / 2);
            if(c1 % 2 != 0)
                res++;
        }
        else if(p == 3)
        {
            if(c1 == c2)
            {
                res += c2;
            }
            else if(c1 > c2)
            {
                res += c2;
                res += ((c1 - c2) / 3);
                if((c1 - c2) % 3 != 0)
                    res++;
            }
            else
            {
                res += c1;
                res += ((c2 - c1) / 3);
                if((c2 - c1) % 3 != 0)
                    res++;
            }
        }
        else if(p == 4)
        {
            int remain = 0;
            if(c1 == c3)
            {
                res += c3;
            }
            else if(c1 > c3)
            {
                res += c3;
                remain = c1 - c3;
            }
            else
            {
                res += c1;
                remain = c3 - c1;
            }
           
            c2 += remain / 2;
            res += (c2 / 2);
            if(c2 % 2 != 0 || (c2 % 2 == 0 && remain % 2 == 1))
                res++;
            
        }


        printf("Case #%d: %d\n", ii, res);
    }
}
