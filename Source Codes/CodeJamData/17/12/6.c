#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>
#include <math.h>

#ifdef GCJ_DEBUG
#define DEBUGF(s, ...) if (t+1 == GCJ_DEBUG) fprintf(stderr, "DEBUG #%d: " s, t+1, ##__VA_ARGS__)
#else
#define DEBUGF(s, ...) (void)0
#endif

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int s_min[100][100];
int s_max[100][100];
int used[100][100];
int max_kits;

void do_recurse(int t, int n, int p, int ri, int rs_min, int rs_max, int kits)
{
	int j;

	for (j = 0; j < p && max_kits < p; j++)
	{
		if (!used[ri][j])
		{
			int new_min = MAX(rs_min, s_min[ri][j]);
			int new_max = MIN(rs_max, s_max[ri][j]);

			if (new_min <= new_max && new_max > 0)
			{	
				DEBUGF("Adding ingredient %d package %d to kit %d (%d <= S <= %d)\n", ri, j, kits, new_min, new_max);
				used[ri][j] = 1;

				if ((ri + 1) == n)
				{
					/* Kit complete */
					if (kits > max_kits)
						max_kits = kits;
					/* Go back to first ingredient and start a new kit */
					do_recurse(t, n, p, 0, 0, INT_MAX, kits + 1);
				}
				else
				{
					do_recurse(t, n, p, ri + 1, new_min, new_max, kits);
				}

				used[ri][j] = 0;
			}
		}
	}
}

void do_test(int t)
{
	int n, p;
	int r[100];

	int i, j;

	scanf("%d %d", &n, &p);

	for (i = 0; i < n; i++)
		scanf("%d", &r[i]);

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < p; j++)
		{ 
			int q;
			scanf("%d", &q);
			
			s_min[i][j] = ceil(q / (1.1 * r[i]));
			s_max[i][j] = floor(q / (0.9 * r[i]));
			used[i][j] = 0;
			DEBUGF("ingredient %d package %d: %d <= S <= %d\n", i, j, s_min[i][j], s_max[i][j]);
		}
	}
	
	max_kits = 0;
	do_recurse(t, n, p, 0, 0, INT_MAX, 1);

	printf("Case #%d: %d\n", t + 1, max_kits);
}

int main()
{
	int t, i;

	scanf("%d", &t);
	
	for (i = 0; i < t; i++)
		do_test(i);

	return 0;
}
