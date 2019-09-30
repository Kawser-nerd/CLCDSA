#include <stdio.h>

typedef unsigned long long int ulli;
int T, N, M;
ulli At[128];
ulli Bt[128];
ulli An[128];
ulli Bn[128];

ulli max, ultimate;

#define min(a,b) ((a) < (b) ? (a) : (b))

void search (int a, int b)
{
	ulli save;

	if (a >= N)
		return;

	if (b >= M)
		return;

	if (At[a] == Bt[b])
	{
		save = min(An[a], Bn[b]);
		max += save;
		An[a] -= save;
		Bn[b] -= save;

		if (max > ultimate)
			ultimate = max;
	}


	if (An[a])
		search (a, b + 1);
	if (Bn[b])
		search (a + 1, b);

	search (a + 1, b + 1);

	if (At[a] == Bt[b])
	{
		max -= save;
		An[a] += save;
		Bn[b] += save;
	}
}

int main(void)
{
	int now, i, j;

	scanf ("%d", &T);

	now = T;
	while (now--)
	{
		scanf("%d%d", &N, &M);

		for (i = 0; i < N; i++)
			scanf("%llu%llu", &An[i], &At[i]);
		for (i = 0; i < M; i++)
			scanf("%llu%llu", &Bn[i], &Bt[i]);

		max = 0;
		ultimate = 0;

		search(0, 0);

		printf("Case #%d: %llu\n", T - now, ultimate);
	}
}
