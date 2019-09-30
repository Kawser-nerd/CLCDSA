#include <stdio.h>
#include <stdlib.h>

int compIntC(const void *int1, const void *int2)
{
    return (*(int*)int1 - *(int*)int2);
}

int compIntD(const void *int1, const void *int2)
{
    return (*(int*)int2 - *(int*)int1);
}


int main()
{
    int v1;
    int v2;
    int v1p[1000];
    int v2p[1000];
    int v1n[1000];
    int v2n[1000];
    int c1p, c1n, c2p, c2n, c1z, c2z;
    int n;
    int nCases;
    int minSum;
    scanf("%i", &nCases);
    //printf("Casos: %i\n", nCases);
    for(int c = 1; c <= nCases; c++)
    {
        c1p = 0;
        c2p = 0;
        c1n = 0;
        c2n = 0;
        c1z = 0;
        c2z = 0;

        scanf("%i", &n);
        //printf("%i Elementos por vetor\n", n);
        for(int i = 0; i < n; i++)
        {
            scanf("%i", &v1);
            if(v1 > 0)
            {
                v1p[c1p] = v1;
                c1p++;
            }
            else if (v1 < 0)
            {
                v1n[c1n] = v1;
                c1n++;
            }
            else
                c1z++;
        }
        for(int i = 0; i < n; i++)
        {
            scanf("%i", &v2);
            if(v2 > 0)
            {
                v2p[c2p] = v2;
                c2p++;
            }
            else if(v2 < 0)
            {
                v2n[c2n] = v2;
                c2n++;
            }
            else
                c2z++;
        }
        //printf("c1p: %i c1n: %i c2p: %i c2n: %i\n", c1p, c1n, c2p, c2n);
        qsort(v1p, c1p, sizeof(int), compIntC);
        qsort(v1n, c1n, sizeof(int), compIntD);
        qsort(v2p, c2p, sizeof(int), compIntC);
        qsort(v2n, c2n, sizeof(int), compIntD);

/*
        printf("v1p:\n");
        for(int i = 0; i < c1p; i++)
            printf("%i ", v1p[i]);
        printf("\n");

        printf("v1n:\n");
        for(int i = 0; i < c1n; i++)
            printf("%i ", v1n[i]);
        printf("\n");

        printf("v2p:\n");
        for(int i = 0; i < c2p; i++)
            printf("%i ", v2p[i]);
        printf("\n");

        printf("v2n:\n");
        for(int i = 0; i < c2n; i++)
            printf("%i ", v2n[i]);
        printf("\n");
*/
        minSum = 0;

        while((c1p > 0) && (c2n > 0))
        {
            minSum += v1p[c1p-1] * v2n[c2n-1];
            //printf("multiplicando %i(1) e %i(2)\n", v1p[c1p-1], v2n[c2n-1]);
            c1p--;
            c2n--;
        }

        while((c1n > 0) && (c2p > 0))
        {
            minSum += v1n[c1n-1] * v2p[c2p-1];
            //printf("multiplicando %i(1) e %i(2)\n", v1n[c1n-1], v2p[c2p-1]);
            c1n--;
            c2p--;
        }

        if((c1p > 0) && (c2p > 0) && (c1n == 0) && (c2n == 0))
        {
            if(c1p >= c2z)
            {
                c1p = c1p - c2z;
                c2z = 0;
            }
            else
            {
                c1p = 0;
                c2z = c2z - c1p;
            }

            if(c2p > c1z)
            {
                c2p = c2p - c1z;
                c1z = 0;
            }
            else
            {
                c2p = 0;
                c1z = c1z - c2p;
            }
            if(c1p > c2p)
                c1p = c2p;
            else if(c1p < c2p)
                c2p = c1p;
            for(int i = 0; i < c1p; i++)
            {
                minSum += v1p[i] * v2p[c1p-i-1];
            }
        }
        else if((c1n > 0) && (c2n > 0) && (c1p == 0) && (c2p == 0))
        {
            if(c1n >= c2z)
            {
                c1n = c1n - c2z;
                c2z = 0;
            }
            else
            {
                c1n = 0;
                c2z = c2z - c1n;
            }

            if(c2n > c1z)
            {
                c2n = c2n - c1z;
                c1z = 0;
            }
            else
            {
                c2n = 0;
                c1z = c1z - c2n;
            }
            if(c1n > c2n)
                c1n = c2n;
            else if(c1n < c2n)
                c2n = c1n;
            for(int i = 0; i < c1n; i++)
            {
                minSum += v1n[i] * v2n[c1n-i-1];
            }
        }



        printf("Case #%i: %i\n", c, minSum);
    }
}
