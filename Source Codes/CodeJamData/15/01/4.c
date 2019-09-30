/* Google Code Jam Qualification Round 2015
 * Problem A. Standing Ovation
 * Solution in C
 * By Smithers
 */

#include <stdio.h>

int main()
{
    int T, x;
    char string[1001];
    char *p;
    int n, f, y;
    
    scanf("%d", &T);
    for (x = 1; x <= T; x++)
    {
        scanf("%*d %s", string);
        
        n = 0;
        f = 0;
        for (p = string; *p; p++)
        {
            n += *p - '0';
            if (n > 0)
                n--;
            else
                f++;
        }
        
        printf("Case #%d: %d\n", x, f);
    }
    
    return 0;
}