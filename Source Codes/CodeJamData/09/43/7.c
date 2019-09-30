#include <stdio.h>
#include <stdlib.h>

int n, k;
int price[110][30];

int legj;
int hol[110];

int lehet(int a, int b)
{
	int i;
	for (i = 0; i < k; i++) {
		if ((__int64)(price[a][i]-price[b][i])*(__int64)(price[a][0]-price[b][0]) <= 0) return 0;
	}
	return 1;
}

void bt(int l, int sn)
{
	int i, j;
	if (sn > legj) return;
	if (l == n) {
		if (sn < legj) legj = sn;
		return;
	}
	for (i = 0; i < sn; i++) {
		for (j = 0; j < l; j++) {
			if (hol[j] == i) {
				if (!lehet(l, j)) goto rossz;
			}
		}
		hol[l] = i;
		bt(l+1, sn);
rossz:;
	}
	hol[l] = sn;
	bt(l+1, sn+1);
}

void main(void)
{
	int t, ti;
	scanf("%d", &t);
	for (ti = 1; ti <= t; ti++) {
		int i, j;
		scanf("%d %d", &n, &k);
		for (i = 0; i < n; i++) {
			for (j = 0; j < k; j++) {
				scanf("%d", price[i]+j);
			}
		}
		legj = n;
		bt(0, 0);
		printf("Case #%d: %d\n", ti, legj);
	}
}