/* Google Code Jam Round 1B 2017
 * Problem B. Stable Neigh-bors
 * Solution in C
 * By Smithers
 */

#include <stdio.h>

int main()
{
    int t, x;
    int n, r, o, y, g, b, v;
    int r_, y_, b_;
    int lastused;
    int i;
    
    scanf("%d ", &t);
    for (x = 1; x <= t; x++)
    {
        scanf("%d%d%d%d%d%d%d", &n, &r, &o, &y, &g, &b, &v);
        printf("Case #%d: ", x);
        
        r_ = r - g;
        y_ = y - v;
        b_ = b - o;
        
        if (r * 2 == n && g * 2 == n)
        {
            while (r--)
                printf("RG");
        }
        else if (y * 2 == n && v * 2 == n)
        {
            while (y--)
                printf("YV");
        }
        else if (b * 2 == n && o * 2 == n)
        {
            while (b--)
                printf("BO");
        }
        else if (g > 0 && g >= r ||
                 v > 0 && v >= y ||
                 o > 0 && o >= b ||
                 r_ > y_ + b_ ||
                 y_ > b_ + r_ ||
                 b_ > r_ + y_)
        {
            printf("IMPOSSIBLE");
        }
        else
        {
            lastused = -1;
            while (r_ || y_ || b_)
            {
                switch (lastused)
                {
                case -1:
                    i = r_ ? 0 : 1;
                    break;
                case 0:
                    i = b_ > y_ ? 2 : 1;
                    break;
                case 1:
                    i = b_ > r_ ? 2 : 0;
                    break;
                case 2:
                    i = y_ > r_ ? 1 : 0;
                    break;
                }
                switch (i)
                {
                case 0:
                    for (; g; g--)
                        printf("RG");
                    printf("R");
                    r_--;
                    break;
                case 1:
                    for (; v; v--)
                        printf("YV");
                    printf("Y");
                    y_--;
                    break;
                case 2:
                    for (; o; o--)
                        printf("BO");
                    printf("B");
                    b_--;
                    break;
                }
                lastused = i;
            }
        }
        printf("\n");
    }
    return 0;
}
