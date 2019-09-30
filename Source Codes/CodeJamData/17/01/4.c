/* Google Code Jam Qualification Round 2017
 * Problem A. Oversized Pancake Flipper
 * Solution in C
 * By Smithers
 */

#include <stdio.h>

int main()
{
    int t, x;
    int n, k;
    int a[1000];
    int y;
    int c1, c2;
    int i;
    
    scanf("%d ", &t);
    for (x = 1; x <= t; x++)
    {
        c1 = '+';
        for (n = 0; (c2 = getc(stdin)) != ' '; n++)
        {
            a[n] = c2 != c1;
            c1 = c2;
        }
        scanf("%d ", &k);
        y = 0;
        for (i = 0; i < n; i++)
        {
            if (!a[i])
                continue;
            if (i + k > n)
            {
                y = -1;
                break;
            }
            else if (i + k < n)
            {
                a[i + k] ^= 1;
            }
            y++;
        }
        if (y < 0)
            printf("Case #%d: IMPOSSIBLE\n", x);
        else
            printf("Case #%d: %d\n", x, y);
    }
    return 0;
}
