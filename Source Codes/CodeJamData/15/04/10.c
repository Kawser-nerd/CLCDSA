#include <assert.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <limits.h>
#include <stddef.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
int i_min(int x, int y)
{
    return x <= y ? x : y;
}
int i_max(int x, int y)
{
    return x >= y ? x : y;
}
int main()
{
    int tc, cc;
    int x, r, c;
    int ok;
    scanf("%d", &tc);
    for (cc = 1; cc <= tc; ++cc)
    {
        scanf("%d%d%d", &x, &r, &c);
        switch (x)
        {
            case 1:
                ok = 1;
                break;
            case 2:
                ok = (r * c) % 2 == 0;
                break;
            case 3:
                ok = i_min(r, c) >= 2 && (r * c) % 3 == 0;
                break;
            default:
                ok = i_min(r, c) >= 3 && i_max(r, c) == 4;
                break;
        }
        printf("Case #%d: %s\n", cc, ok ? "GABRIEL" : "RICHARD");
    }
    return 0;
}
