#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#define MAX 200000

struct neta_t {
	int t, d;
};


/* ????????????? */
int cmp(const void* a, const void* b) {
	const struct neta_t* x = (const struct neta_t*)a, *y = (const struct neta_t*)b;
	if (x->d > y->d) return -1;
	if (x->d < y->d) return 1;
	if (x->t < y->t) return -1;
	return x->t > y->t;
}

int N, K;
struct neta_t neta[MAX];
char tabeta_neta[MAX] = {0};
struct neta_t kisyutu_neta[MAX];
int kncount = 0;

void read_data(void) {
	int i;
	if (scanf("%d%d", &N, &K) != 2) exit(1);
	for (i = 0; i < N; i++) {
		if (scanf("%d%d", &neta[i].t, &neta[i].d) != 2) exit(1);
	}
}

int main(void) {
	int i;
	int64_t ans = 0;
	int64_t cans = 0;
	int64_t score = 0;
	int64_t syurui = 0;
	read_data();
	qsort(neta, N, sizeof(*neta), cmp);
	/* ?????????????? */
	for (i = 0; i < K; i++) {
		score += neta[i].d;
		if (tabeta_neta[neta[i].t]) {
			kisyutu_neta[kncount++] = neta[i];
		} else {
			syurui++;
		}
		tabeta_neta[neta[i].t] = 1;
	}
	ans = score + syurui * syurui;
	/* ????????? */
	for (i = K; i < N; i++) {
		if (kncount > 0 && !tabeta_neta[neta[i].t]) {
			score -= kisyutu_neta[--kncount].d;
			score += neta[i].d;
			syurui++;
			tabeta_neta[neta[i].t] = 1;
			cans = score + syurui * syurui;
			if (cans > ans) ans = cans;
		}
	}
	printf("%"PRId64"\n", ans);
	return 0;
}