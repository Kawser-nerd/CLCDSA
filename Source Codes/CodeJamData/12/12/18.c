#include <stdio.h>
#include <stdlib.h>

int n;
int a[1024][2];
int ar[1024];

int main()
{
	int ntest, itest;
	FILE *fin = fopen("B-large.in", "r");
	FILE *fout = fopen("B-large.out", "w");
	fscanf(fin, "%d", &ntest);
	for ( itest = 0; ++itest <= ntest; )
	{
		int rate = 0;
		int i, res = 0, l2;
		fscanf(fin, "%d", &n);
		for ( i = 0; i < n; ++i )
			fscanf(fin, "%d%d", a[i], a[i]+1);
		for ( i = 0; i < n; ++i )
			ar[i] = 0;
		for ( l2 = 0; l2 < n; )
		{
			int best, bestb;
			for ( i = 0; i < n; ++i )
				if ( ar[i] < 2 && rate >= a[i][1] )
				{
					++rate;
					if ( ar[i] == 0 )
						++rate;
					ar[i] = 2;
					++res;
					++l2;
					break;
				}
			if ( i < n )
				continue;
			for ( best = -1, i = 0; i < n; ++i )
				if ( ar[i] == 0 && rate >= a[i][0] && ( best < 0 || bestb < a[i][1] ) )
				{
					best = i;
					bestb = a[i][1];
				}
			if ( best < 0 )
				break;
			++rate;
			ar[best] = 1;
			++res;
		}
		if ( l2 < n )
			fprintf(fout, "Case #%d: Too Bad\n", itest);
		else
			fprintf(fout, "Case #%d: %d\n", itest, res);
	}
	return 0;
}
