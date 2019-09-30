#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int t;
	int d;
} REC;

REC la[200], lb[200];

int cmp(const void *aa, const void *bb)
{
	const REC* a = (const REC*)aa;
	const REC* b = (const REC*)bb;
	if (a->t != b->t) return a->t - b->t;
	return b->d - a->d;
}

int main()
{
	int n;

	scanf("%d", &n);
	for (int c = 1; c <= n; c++)
	{
		int t, na, nb;

		scanf("%d", &t);
		scanf("%d %d", &na, &nb);
		
		for (int i = 0; i < na; i++)
		{
			int h1, m1, h2, m2;
			scanf("%d:%d %d:%d", &h1, &m1, &h2, &m2);
			la[i].t = 60*h1 + m1;
			la[i].d = -1;
			lb[i].t = 60*h2 + m2 + t;
			lb[i].d = +1;
		}

		for (int i = na; i < na+nb; i++)
		{
			int h1, m1, h2, m2;
			scanf("%d:%d %d:%d", &h1, &m1, &h2, &m2);
			lb[i].t = 60*h1 + m1;
			lb[i].d = -1;
			la[i].t = 60*h2 + m2 + t;
			la[i].d = +1;
		}

		qsort(la, na+nb, sizeof(REC), cmp);
		qsort(lb, na+nb, sizeof(REC), cmp);

		int ma = 0, ca = 0;
		for (int i = 0; i < na+nb; i++)
		{
			ca += la[i].d;
			if (ca < ma) ma = ca;
		}

		int mb = 0, cb = 0;
		for (int i = 0; i < na+nb; i++)
		{
			cb += lb[i].d;
			if (cb < mb) mb = cb;
		}
		printf("Case #%d: %d %d\n", c, -ma, -mb);
	}
	return 0;
}
