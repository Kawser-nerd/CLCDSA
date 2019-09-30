#include <stdio.h>
#include <string.h>
#include <string.h>
#include <stdlib.h>

double aux_small(
		int n,
		int *e, int *s,
		int **d,
		int u, int v,
		int e_left, int current_s
) {
	int dist = d[u][u+1];
	double rv1 = -1.;
	double rv2 = -1.; 

	if (u == v)
		return 0.;

	if (dist <= e_left) {
		// can continue on same horse
		double delta_t = ((double) dist) / ((double) current_s);
		rv1 = delta_t + aux_small(n, e, s, d, u+1, v,
				e_left - dist, current_s);
	}

	if (dist <= e[u]) {
		e_left = e[u];
		double delta_t = ((double) dist) / ((double) s[u]);
		e_left -= dist;
		rv2 = delta_t + aux_small(n, e, s, d, u+1, v, e_left, s[u]);
	}

	if ((rv1 > 0.) && (rv2 > 0.))
		return (rv1 < rv2)? rv1 : rv2;
	else
		return (rv1 < 0.)? rv2 : rv1;
}

void solve_test_case(
		int case_idx,
		int n, int q,
		int *e, int *s,
		int **d,
		int *u, int *v
) {
	printf("Case #%d:", case_idx);
	for (int i = 0; i < q; ++i) {
		double result = aux_small(n, e, s, d, u[i], v[i], 0, 0);
		printf(" %f", result);
	}
	printf("\n");

	/*double earliest_finish = 0.;
	for (int i = 0; i < n; ++i) {
		double tmp = ((double) (d - k[i])) / ((double) s[i]);
		if (tmp > earliest_finish)
			earliest_finish = tmp;
	}
	printf("Case #%d: %f\n", case_idx,
			((double) d)/((double) earliest_finish));*/
}

int main(void) {
	int n_test_cases;
	scanf("%d", &n_test_cases);
	for (int i = 0; i < n_test_cases; ++i) {
		int n, q;
		int e[100];
		int s[100];
		int *d[100];
		int u[100];
		int v[100];
		scanf("%d%d", &n, &q);
		for (int i = 0; i < n; ++i)
			scanf("%d%d", &(e[i]), &(s[i]));
		for (int i = 0; i < n; ++i) {
			d[i] = calloc(100, sizeof(int));
			for (int j = 0; j < n; ++j)
				scanf("%d", &(d[i][j]));
		}
		for (int i = 0; i < q; ++i) {
			scanf("%d%d", &(u[i]), &(v[i]));
			u[i]--;
			v[i]--;
		}
		solve_test_case(i+1, n, q, e, s, d, u, v);
	}
	return 0;
}
