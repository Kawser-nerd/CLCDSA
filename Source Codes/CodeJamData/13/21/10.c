#include <stdio.h>
#include <stdlib.h>

#define NMAX 100

int cmp_int(const void *p, const void *q)
{
    int a = *(const int *)p, b = *(const int *)q;
    return a < b ? -1 : a > b ? 1 : 0;
}

int main()
{
    int t, c;
    int a, n, motes[NMAX];
    int r, i, j;
    
    scanf("%d", &t);
    for (c = 1; c <= t; c++)
    {
        scanf("%d%d", &a, &n);
        for (i=0; i<n; i++)
            scanf("%d", &motes[i]);
        
        r = n;
        if (a > 1)
        {
            qsort(motes, n, sizeof(*motes), cmp_int);
            j = 0;
            for (i=0; i<n; i++)
            {
                while (a <= motes[i])
                {
                    j++;
                    a = 2*a - 1;
                }
                if (j + (n-i-1) < r)
                    r = j + (n-i-1);
                a += motes[i];
            }
        }
        printf("Case #%d: %d\n", c, r);
    }
    return 0;
}
