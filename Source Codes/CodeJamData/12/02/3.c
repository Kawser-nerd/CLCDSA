#include <stdio.h>

/* Problem B. Dancing With the Googlers */
/* Part I - Determine the best score for each googler
 * for surprising and unsurprising triplets in C */

int main()
{
    int t, n, s, p, x;
    int c, i;
    
    scanf("%d", &t);
    printf("%d\n", t);
    for (c=1; c<=t; c++)
    {
        scanf("%d%d%d", &n, &s, &p);
        printf("%d %d %d\n", n, s, p);
        for (i=0; i<n; i++)
        {
            scanf("%d", &x);
            if (i)
                printf(" ");
            printf("%d,%d", (x+2)/3, (x>1 && x<29) * ((x+2)/3 + (x%3!=1)));
        }
        printf("\n");
    }
    
    return 0;
}
