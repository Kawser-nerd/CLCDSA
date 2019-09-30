//
//	Google CodeJam 2010 - Round 1C, Problem A
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


int a[1000], b[1000];
int N;


void main (void)
{
	int iCase, nCases;
    int i, j, ni;
    int da, db;

#ifdef TEST
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
#endif

	scanf ("%d\n", &nCases);
	for (iCase = 1; iCase <= nCases; iCase++)
	{
    	scanf ("%d\n", &N);
        for (i = 0; i < N; i++)
            scanf ("%d %d\n", &a[i], &b[i]);

        ni = 0;
        for (i = 0; i < N; i++)
        {
            for (j = i; j < N; j++)
            {
                da = a[j] - a[i];
                db = b[i]-a[i]-b[j]+a[j];
                if (db != 0)
                {
                    if (da > 0)
                    {
                        if (db > da)
                            ni++;
                    }
                    else
                    {
                        if (-db > -da)
                            ni++;
                    }
                }

            }
        }

        printf ("Case #%d: %d\n", iCase, ni);
	}
}
