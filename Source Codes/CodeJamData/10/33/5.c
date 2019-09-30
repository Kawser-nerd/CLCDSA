//
//	Google CodeJam 2010 - Round 1C, Problem C
//	DQuadros
//
//	Tested with Microsoft Visual C++ v6
//


// If the following defines are uncommented:
// - Uses test files instead of standard input/output
// - Enables debug printfs
//#define TEST
//#define DUMP

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FALSE   0
#define TRUE    1

char bark [512][512];
int N, M;

struct
{
    int tam;
    int n;
} result [512];
int nr;

#ifdef DUMP
void Dump (void)
{
    int i, j;

    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
            printf ("%c ", bark[i][j]);
        printf ("\n");
    }
}
#endif


void Count (int t)
{
    int i, i1;
    int j, j1;
    char cr, cc;
    int found = FALSE;
    int ok;

    result[nr].tam = t;
    result[nr].n = 0;
    for (i = 0; i <= (M-t); i++)
    {
        for (j = 0; j <= (N-t); j++)
        {
            cr = bark[i][j];
            if (cr == 'X')
                continue;
            ok = TRUE;
            for (i1 = 0; ok && (i1 < t); i1++)
            {
                cc = cr;
                for (j1 = 0; ok && (j1 < t); j1++)
                {
                    if (bark[i+i1][j+j1] != cc)
                        ok = FALSE;
                    cc = cc ^ 1;
                }
                cr = cr ^1;
            }
            if (ok)
            {
                found = TRUE;
                result[nr].n++;
                for (i1 = 0; i1 < t; i1++)
                    for (j1 = 0; j1 < t; j1++)
                        bark[i+i1][j+j1] = 'X';
            }
        }
    }
    if (found)
        nr++;
}

void main (void)
{
	int iCase, nCases;
    int i, j;
    int h;
    int t;
    char hex [130];

#ifdef TEST
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
#endif

	scanf ("%d\n", &nCases);
	for (iCase = 1; iCase <= nCases; iCase++)
	{
    	scanf ("%d %d\n", &M, &N);
        for (i = 0; i < M; i++)
        {
            scanf ("%s\n", hex);
            for (j = 0; j < N/4; j++)
            {
                if (hex[j] <= '9')
                    h = hex[j] - '0';
                else
                    h = hex[j] - 'A' + 10;
                if (h & 8)
                    bark [i][j*4] = '1';
                else
                    bark [i][j*4] = '0';
                if (h & 4)
                    bark [i][j*4+1] = '1';
                else
                    bark [i][j*4+1] = '0';
                if (h & 2)
                    bark [i][j*4+2] = '1';
                else
                    bark [i][j*4+2] = '0';
                if (h & 1)
                    bark [i][j*4+3] = '1';
                else
                    bark [i][j*4+3] = '0';
            }
        }

#ifdef DUMP
        Dump ();
#endif

        nr = 0;
        t = M;
        if (N < M)
            t = N;
        while (t > 0)
        {
            Count (t);
            t--;
        }

#ifdef DUMP
        Dump ();
#endif


        printf ("Case #%d: %d\n", iCase, nr);
        for (i = 0; i < nr; i++)
            printf ("%d %d\n", result[i].tam, result[i].n);
	}
}
