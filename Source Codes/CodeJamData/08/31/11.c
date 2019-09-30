#include <stdio.h>
#include <stdlib.h>

int P;
int K;
int L;
int F[1001];

int cmp(void *a, void *b)
{
	int *c = a;
	int *d = b;

	return *d-*c; 
}

int solve()
{
	int FR[1001];
	int i;
	int m;
	int v;

	for (i=0; i<L; i++)
		FR[i]=F[i];

	qsort(FR, L, sizeof(int), cmp);


	m=0;
	v=0;
	for (i=0; i<L; i++)
	{
		if (i%K==0)
		{
			m++;
		}

		if (FR[i] && m>P)
			return -1;
		v+=FR[i]*m;
	}

	return v; 

}

int main(void)
{
	int N;
	int tc;
	int i;
	int v;

	scanf ("%d", &N);


	for (tc=1; tc<=N; tc++)
	{
		scanf ("%d %d %d", &P, &K, &L);
		for (i=0; i<L; i++)
			scanf ("%d", F+i);

		v=solve();
		if (v>0)
		{
			printf ("Case #%d: %d\n", tc, v);
		} else
		{
			printf ("Case #%d: Impossible\n", tc, v);

		}
	}


}