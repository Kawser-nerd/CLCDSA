#include <stdio.h>
#include <stdlib.h>


int absV(int n) {return n < 0 ? -n : n;}
int min(int n1, int n2) {return n1 < n2 ? n1 : n2;}

struct item {
	int v;
	int p;
};

int N, X;
struct item is[1001];
int sizes[1001];
int newS[1001];
int used[1001];
int cache[1001][1001];
int amoLeft[1001];
int amoRight[1001];

struct item temp[1001];


void sort(int s, int e) {
	if (e - s <= 1) {
		return;
	}
	int m = (s + e) / 2;
	sort(s, m);
	sort(m, e);
	int i;
	int p1 = s;
	int p2 = m;
	for (i = 0; i < e - s; i++) {
		if (p2 == e || (p1 < m && is[p1].v < is[p2].v)) {
			temp[i] = is[p1++];
		} else {
			temp[i] = is[p2++];
		}
	}
	for (i = 0; i < e - s; i++) {
		is[s + i] = temp[i];
	}
}

int dp(int left, int right) {
	if (left + right == N) {
		return 0;
	}
	if (cache[left][right] != -1) {
		return cache[left][right];
	}
	int p = left + right;
	int res1 = dp(left + 1, right) + amoLeft[p];
	int res2 = dp(left, right + 1) + amoRight[p];
	int best = min(res1, res2);
	cache[left][right] = best;
	return best;
}

void handle() {
	scanf ("%d ", &N);
	int i, j;
	for (i = 0; i < N; i++) {
		int v;
		scanf("%d ", &v);
		is[i].v = v;
		is[i].p = i;
		amoLeft[i] = amoRight[i] = 0;
	}
	sort(0, N);
	for (i = 0; i <= N; i++) {
		for (j = 0; j <= N; j++) {
			cache[i][j] = -1;
		}
	}
	for (i = 0; i < N; i++) {
		for (j = i + 1; j < N; j++) {
			if (is[j].p < is[i].p) {
				amoLeft[i]++;
			} else {
				amoRight[i]++;
			}
		}
	}
	printf ("%d\n", dp(0, 0));
}

int main() {
	int t;
	scanf ("%d ", &t);
	int i;
	for (i = 0; i < t; i++) {
		printf ("Case #%d: ", i + 1);
		handle();
	}
	return 0;
}