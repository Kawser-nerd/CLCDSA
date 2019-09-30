/* Google Code Jam Round 1B 2017
 * Problem A. Steed 2: Cruise Control
 * Solution in C
 * By Smithers
 */

#include <stdio.h>

int main()
{
    int t, x;
    int d, n;
    int k, s;
    double time, maxtime;
    double y;
    
    scanf("%d ", &t);
    for (x = 1; x <= t; x++)
    {
        scanf("%d%d", &d, &n);
        maxtime = 0;
        while (n--)
        {
            scanf("%d%d", &k, &s);
            time = (double)(d - k) / s;
            if (time > maxtime)
                maxtime = time;
        }
        y = d / maxtime;
        printf("Case #%d: %f\n", x, y);
    }
    return 0;
}
