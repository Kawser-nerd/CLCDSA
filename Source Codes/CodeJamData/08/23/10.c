//
//	Google CodeJam - OnLine Round 1B, Problem C
//	DQuadros
//
//	Tested with Microsoft Visual C++ v6
//

// If the following define is uncommented:
// - Uses test files instead of standard input/output
// - Enables debug printfs
//#define TEST

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_K   100000

int deck  [MAX_K+1];
unsigned char used [(MAX_K+1) / 8];

void MakeDeck (int K)
{
    int i, pos, count;

    memset (used, 0, sizeof(used));
    for (i = 1, pos = K; i <= K; i++)
    {
        for (count = 0; count != i;)
        {
            pos = pos+1;
            if (pos > K)
                pos = 1;
            if ((used[pos >> 3] & (1 << (pos&7))) == 0)
                count++;
        }
        deck[pos] = i;
        used[pos >> 3] |= (1 << (pos&7));
    }

#ifdef TEST
    for (i = 1; i <= K; i++)
        printf ("%d ", deck[i]);
    printf ("\n");
#endif
}

void main (void)
{
	int iCase, nCases;
    int K, n, d, j;

#ifdef TEST
	freopen("test_in.txt","r",stdin);
	freopen("test_out.txt","w",stdout);
#endif

	scanf ("%d", &nCases);
	for (iCase = 1; iCase <= nCases; iCase++)
	{
        scanf ("%d", &K);
        MakeDeck (K);
		printf ("Case #%d: ", iCase);
        scanf ("%d", &n);
        for (j = 0; j < n; j++)
        {
            scanf ("%d", &d);
            if (j == (n-1))
                printf ("%d\n", deck[d]);
            else
                printf ("%d ", deck[d]);
        }
	}

}
