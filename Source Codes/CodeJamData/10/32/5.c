//
//	Google CodeJam 2010 - Round 1C, Problem B
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



void main (void)
{
	int iCase, nCases;
    int L, P, C;
    unsigned prod;
    int n, r;

#ifdef TEST
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
#endif

	scanf ("%d\n", &nCases);
	for (iCase = 1; iCase <= nCases; iCase++)
	{
    	scanf ("%d %d %d\n", &L, &P, &C);

        prod = L;
        n = 0;
        while (prod < (unsigned) P)
        {
            prod *= C;
            n++;
        }
        r = 0;
        prod = 1;
        while ((unsigned) n > prod)
        {
            prod = prod << 1;
            r++;
        }

        printf ("Case #%d: %d\n", iCase, r);
	}
}
