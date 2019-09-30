#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#ifdef DEBUG
#define ddd(s, ...) printf(s, __VA_ARGS__)
#else
#define ddd(s, ...)
#endif

int rev_cmpdb(const void* v1, const void* v2) {
	const double *d1 = v1;
	const double *d2 = v2;

	if (*d1 < *d2)
		return (1);
	else if (*d1 > *d2)
		return (-1);
	return (0);
}

int play_war(double *n, double *k, int N) {
	int i;
	int k_min = N-1;
	int k_max = 0;
	int n_win = 0;

	for (i=0; i<N; i++) {
		if (n[i] > k[k_max]) {
			n_win++;
			k_min--;
		} else {
			k_max++;
		}
	}
	return (n_win);
}

int main(void) {
	int t, T;

	scanf("%d", &T);
	t = 0;
	while (t<T) {
		int N;
		double n[1000], k[1000];
		int dw = 0, w = 0;
		int i;

		scanf("%d", &N);
		for (i=0; i<N; i++)
			scanf("%lf", &n[i]);
		for (i=0; i<N; i++)
			scanf("%lf", &k[i]);

		qsort(n, N, sizeof(double), rev_cmpdb);
		qsort(k, N, sizeof(double), rev_cmpdb);

		w = play_war(n, k, N);
		dw = N-play_war(k, n, N);

		printf("Case #%d: %d %d\n", t+1, dw, w);
		t++;
	}


	return (0);
}
