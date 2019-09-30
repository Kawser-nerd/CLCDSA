#include <stdio.h>

#define MAXCHICKS 50

int main()
{
    int c, n, k, b, t, x[MAXCHICKS], v[MAXCHICKS];
    int casenum, saved, unsaved, swaps, i;
    
    scanf("%d", &c);
    for (casenum=1; casenum<=c; casenum++)
    {
        scanf("%d%d%d%d", &n, &k, &b, &t);
        for (i=0; i<n; i++)
            scanf("%d", &x[i]);
        for (i=0; i<n; i++)
            scanf("%d", &v[i]);
        
        saved = unsaved = swaps = 0;
        for (i=n-1; i>=0 && saved<k; i--)
            if (t * v[i] >= b - x[i])
                saved++, swaps += unsaved;
            else
                unsaved++;
        
        if (saved == k)
            printf("Case #%d: %d\n", casenum, swaps);
        else
            printf("Case #%d: IMPOSSIBLE\n", casenum);
    }
    
    return 0;
}
