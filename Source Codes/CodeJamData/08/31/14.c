#include <stdlib.h>
#include <stdio.h>
#include "ST.h"
#define DEBUGI(x) printf(#x": %d\n", x)
#define DEBUGD(x) printf(#x": %g\n", x)
#define DEBUGS(x) printf(#x": %s\n", x)
#define DEBUGC(x) printf(#x": %c\n", x)
int letter[1000];

int compare(const void *x, const void *y)
{
    int *a, *b;
    
    a = (int *)x;
    b = (int *)y;

    return (*b) - (*a);
}


int main(void)
{
    register int i, j;
    int N, k;
    int P, K, L;
    double total;
    scanf("%d", &N);
    k = 1;
    
    while (N > 0)
    {    
        scanf("%d %d %d", &P, &K, &L);

        total = 0;

        for (i = 0; i < L; i++)
            scanf("%d", &letter[i]);

        qsort(letter, L, sizeof(int), compare);

        i = 1;
        j = 0;
        while (L > 0)
        {
            if (j >= i * K)
            {
                i++;               
            }
            total += (double)(i * letter[j]);
            j++;
            L--;
        }
        
        printf("Case #%d: %.0f\n", k, total);
        N--;
        k++;
    }
    
    return EXIT_SUCCESS;
}
