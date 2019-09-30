#include <stdio.h>
#include <stdlib.h>

#define N_MAX 100000
#define M_MAX 200000
#define Q_MAX 100000

int unionf[N_MAX];

int nest[N_MAX];

int myon[N_MAX];

int n, m, q;

typedef struct {
	int a;
	int b;
	int y;
} bridge;

typedef struct {
	int v;
	int w;
	int x;
} human;

bridge brid[M_MAX];
human hum[Q_MAX];

int answer[M_MAX];

int unionfind (int where) {
	// printf("union: [%d] %d\n", where, unionf[where]);
	if (unionf[where] == where) {
		return where;
	} else {
		int al = unionfind(unionf[where]);
		unionf[where] = al;
		myon[where] = myon[al];
		return al;
	}
}

void unionunion (int a, int b) {
	a = unionfind(a);
	b = unionfind(b);
	if (a == b) return;
	if (nest[a] < nest[b]) {
		unionf[a] = b;
		myon[a] += myon[b];
		myon[b]  = myon[a];
	} else {
		unionf[b] = a;
		myon[b] += myon[a];
		myon[a]  = myon[b];
		if (nest[a] == nest[b]) nest[a]++;
	}
	return;
}

int howmany (int x) {
	return myon[unionfind(x)];
}

int same(int x, int y) {
	return unionfind(x) == unionfind(y);
}

int sort_bridge (const bridge *a, const bridge *b) {
	return (b->y) - (a->y);
}

int sort_human (const human *a, const human *b) {
	return (b->w) - (a->w);
}

int solve(){
	int i;

	int nextbrid = 0, nexthum = 0;

	qsort(brid, m, sizeof(bridge), sort_bridge);
	qsort(hum , q, sizeof(human ), sort_human );
	// for (i = 0; i < m; i++) printf("%d %d %d\n", brid[i].a, brid[i].b, brid[i].y);
	// 	putchar('\n');
	// for (i = 0; i < q; i++) printf("%d %d %d\n", hum[i].v, hum[i].w, hum[i].x);
	// 	putchar('\n');
	for (i = 0; i < n; i++) {
		unionf[i] = i;
		nest[i] = 0;
		myon[i] = 1;
	}

	while (nexthum < q) {

		// printf("%d %d\n", nextbrid, nexthum);

		// for (i = 0; i < n; i++) printf("%d ", unionf[i]);
		// 	putchar('\n');

		if (nextbrid >= m || brid[nextbrid].y <= hum[nexthum].w) {
			int i;
			int ans = 0;
			// for (i = 0; i < n; i++) {
			// 	// printf("%d/%d...\n", i, n);
			// 	if (same(i, hum[nexthum].v - 1)) ans++;

			// }
			ans = howmany(hum[nexthum].v - 1);
			answer[hum[nexthum].x] = ans;
			nexthum++;
			continue;
		} else {
			unionunion(brid[nextbrid].a - 1, brid[nextbrid].b - 1);
			nextbrid++;
		}
	}

	for (i = 0; i < q; i++) {
		printf("%d\n", answer[i]);
	}

	return 0;
}

int in(){
	int i;
	scanf("%d%d", &n, &m);
	for (i = 0; i < m; i++) {
		scanf("%d%d%d", &(brid[i].a), &(brid[i].b), &(brid[i].y));
	}
	scanf("%d", &q);
	for (i = 0; i < q; i++) {
		scanf("%d%d", &(hum[i].v), &(hum[i].w));
		hum[i].x = i;
	}
	return 0;
}

int main(void){
	in();

	solve();
	return 0;
} ./Main.c: In function ‘solve’:
./Main.c:83:33: warning: passing argument 4 of ‘qsort’ from incompatible pointer type [-Wincompatible-pointer-types]
  qsort(brid, m, sizeof(bridge), sort_bridge);
                                 ^
In file included from ./Main.c:2:0:
/usr/include/stdlib.h:765:13: note: expected ‘__compar_fn_t {aka int (*)(const void *, const void *)}’ but argument is of type ‘int (*)(const bridge *, const bridge *) {aka int (*)(const struct <anonymous> *, const struct <anonymous> *)}’
 extern void qsort (void *__base, size_t __nmemb, size_t __size,
             ^
./Main.c:84:33: warning: passing argument 4 of ‘qsort’ from incompatible pointer type [-Wincompatible-pointer-types]
  qsort(hum , q, sizeof(human ), sort_human );
                                 ^
In file included from ./Main.c:2:0:
/usr/include/stdlib.h:765:13: note: expected ‘__compar_fn_t {aka int (*)(const void *, const void *)}’ but argument is of type ‘int (*)(const human *, const human *) {aka int (*)(const struct <anonymous...