#include <stdio.h>
#include <stdlib.h>

double dist[1500000];

int metodo(double *a, double *b)
{
	return *b-*a;
}

main()
{
	int TC, T = 0;
	int L, t, N, C;
	int i, j;
	double dist_req, tiempo_acum, total;
	scanf("%d", &TC);
	while (T++ < TC) {
		scanf("%d %d %d %d", &L, &t, &N, &C);
		for (i = total = 0; i < C && i < N; i++) {
			scanf("%lf", &dist[i]);
			total += dist[i];
		}
		for (i = C; i < N;) {
			for (j = 0; j < C && i < N; i++, j++) {
				dist[i] = dist[j];
				total += dist[j];
			}
		}
		dist_req = t/2;
		if (dist_req < total)
			tiempo_acum = t;
		else
			tiempo_acum = total*2;
		for (i = 0; i < N && dist_req != 0; i++) {
			if (dist[i] < dist_req) {
				dist_req -= dist[i];
				dist[i] = 0;
			} else {
				dist[i] -= dist_req;
				dist_req = 0;
			}
		}
/*
		for (i = 0; i < N; i++)
			printf(" %.0lf", dist[i]);
		putchar('\n');
*/
		qsort(dist, N, sizeof(double), (__compar_fn_t) metodo);
/*
		for (i = 0; i < N; i++)
			printf(" %.0lf", dist[i]);
		putchar('\n');
*/
		for (i = 0; i < N; i++) {
			if (L) {
				tiempo_acum += dist[i];
				L--;
			} else
				tiempo_acum += dist[i]*2;
		}
		printf("Case #%d: %.0lf\n", T, tiempo_acum);
	}
	return 0;
}

