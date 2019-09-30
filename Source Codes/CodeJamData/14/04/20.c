/* Google Code Jam, Qualification Round 2014
 * Problem D. Deceitful War
 * Solution in C
 * By Smithers
 */

#include <stdio.h>
#include <stdlib.h>

int cmp_double(const void *p, const void *q)
{
    double a = *(const double *)p, b = *(const double *)q;
    return a < b ? -1 : a > b ? 1 : 0;
}

int main()
{
    int t, ti;
    
    int n;
    double mn[1000], mk[1000];
    int i, j;
    int y, z;
    
    scanf("%d", &t);
    for (ti = 1; ti <= t; ti++)
    {
        scanf("%d", &n);
        for (i = 0; i < n; i++)
            scanf("%lf", &mn[i]);
        for (i = 0; i < n; i++)
            scanf("%lf", &mk[i]);
        
        qsort(mn, n, sizeof(double), cmp_double);
        qsort(mk, n, sizeof(double), cmp_double);
        
        y = 0;
        j = 0;
        for (i = 0; i < n; i++)
        {
            if (mn[i] > mk[j])
            {
                y++;
                j++;
            }
        }
        
        z = 0;
        j = n-1;
        for (i = n-1; i >= 0; i--)
        {
            if (mn[i] > mk[j])
                z++;
            else
                j--;
        }
        
        printf("Case #%d: %d %d\n", ti, y, z);
    }
    return 0;
}
