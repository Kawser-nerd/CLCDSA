#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NMAX 200

int cmpint(const void *p, const void *q)
{
    int a = *(const int *)p, b = *(const int *)q;
    return a < b ? -1 : a > b ? 1 : 0;
}

int main()
{
    int t, c;
    int n, s[NMAX], x;
    double minscore, used, diff;
    int i, ssort[NMAX];
    
    scanf("%d", &t);
    for (c = 1; c <= t; c++)
    {
        scanf("%d", &n);
        x = 0;
        minscore = 100;
        for (i=0; i<n; i++)
        {
            scanf("%d", &s[i]);
            x += s[i];
            if (minscore > s[i])
                minscore = s[i];
        }
        
        memcpy(ssort, s, n*sizeof(int));
        qsort(ssort, n, sizeof(int), cmpint);
        
        used = 0;
        for (i=1; i<n; i++)
        {
            diff = ssort[i] - ssort[i-1];
            if (used + diff * i >= x)
                break;
            used += diff * i;
        }
        diff = (x - used) / i;
        minscore = ssort[i-1] + diff;
        
        printf("Case #%d:", c);
        for (i=0; i<n; i++)
        {
            if (s[i] >= minscore)
                printf(" %f", 0.);
            else
                printf(" %f", (minscore - s[i]) * 100 / x);
        }
        printf("\n");
    }
    return 0;
}
