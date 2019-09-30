#include <stdlib.h>
#include <stdio.h>
#include "ST.h"

static long X[100000];
static long Y[100000];
static long n, A, B, C, D, x0, y0, M;


void generatePoints()
{
    long x, y, i;

    x = x0;
    y = y0;
    X[0] = x0;
    Y[0] = y0;
    /* printf("%ld %ld\n", X[0], Y[0]);*/
    for (i = 1; i < n; i++)
    {
        X[i] = (A * X[i - 1] + B) % M;
        Y[i] = (C * Y[i - 1] + D) % M;
        /*    printf("%ld %ld\n", X[i], Y[i]);*/
    }
}

int main(void)
{
    int N, k, answer;
    register int i, j, l;
    


    scanf("%d", &N);
    k = 1;
    
    while (N > 0)
    {    
        answer = 0;
        scanf("%ld %ld %ld %ld %ld %ld %ld %ld", &n, &A, &B, &C, &D, &x0, &y0, &M);
        generatePoints();

        for (i = 0; i < n; i++)
            for (j = i + 1; j < n; j++)
                for (l = j + 1; l < n; l++)
                {
                    if ((X[i] + X[j] + X[l]) % 3 == 0 &&
                        (Y[i] + Y[j] + Y[l]) % 3 == 0)                       
                        answer++;
                }
        
        printf("Case #%d: %d\n", k, answer);
        N--;
        k++;
    }
    
    return EXIT_SUCCESS;
}
