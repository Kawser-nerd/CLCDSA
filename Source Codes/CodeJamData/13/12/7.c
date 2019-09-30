#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXN 10000

int v[MAXN];
int avail[MAXN];
int req[MAXN];
int actn[MAXN];

/* Sort in descending value order, then increasing index */
int compare(const void *a, const void *b)
{
	const int *an = a;
	const int *bn = b;

	if (v[*an] < v[*bn])
		return 1;

	if (v[*an] > v[*bn])
		return -1;

	return (*an > *bn) - (*an < *bn);
}

void do_test(int t)
{
	int e, r, n;
	int i;
	long long gain = 0;

	scanf("%d%d%d", &e, &r, &n);

	for (i = 0; i < n; i++)
		scanf("%d", &v[i]);

	for (i = 0; i < n; i++)
	{
		/* Used is avail - required */
		avail[i] = e;
		req[i] = 0;
		actn[i] = i;
	}

	qsort(actn, n, sizeof actn[0], compare);

	for(i = 0; i < n; i++)
	{
		int j;
		int av = req[actn[i]] + r;
		int rq = avail[actn[i]] - r;

//		fprintf(stderr, "%d: Using %d energy at activity %d\n", t+1, avail[actn[i]] - req[actn[i]], actn[i]);
		gain += (long long)v[actn[i]] * (avail[actn[i]] - req[actn[i]]);

		if (avail[actn[i]] == req[actn[i]])
			continue;
		/* Start at next position and go forward,
		 * updating 'avail' to req + R... */
		for (j = actn[i] + 1; j < n && v[j] <= v[actn[i]] && av < e; j++, av += r)
		{
//			fprintf(stderr, "%d: Reducing available energy at activity %d to %d\n", t+1, j, av);
			avail[j] = av;
		}

		/* Start at previous position and go backwards,
		 * updating 'req' to avail -R ... */
		for (j = actn[i] - 1; j >= 0 && v[j] < v[actn[i]] && rq > 0; j--, rq -= r)
		{
//			fprintf(stderr, "%d: Increaasing required energy at activity %d to %d\n", t+1, j, rq);
			req[j] = rq;
		}
	}

	printf("Case #%d: %lld\n", t + 1, gain);
}

int main()
{
	int t, i;

	scanf("%d", &t);
	
	for (i = 0; i < t; i++)
		do_test(i);

	return 0;
}
