#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <complex>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cassert>
#include <queue>
#include <cctype>
using namespace std;

typedef long double Real;

const Real o = 1e-8;
const Real pi = acos(-1.0);
const int oo = 0x7fffffff;

const int max_p = 12;
const int max_n = (1 << max_p);

int P, n;
int a[max_n], limit[max_n], c[max_n][max_p];
int T, I;

void input() {
	scanf("%d", &P);
	n = (1 << P);
	for (int i = 0; i < n; i++)
		scanf("%d", &limit[i]);
	int start = n - 1;
	for (int i = 0; i < P; i++) {
		start = (start - 1) / 2;
		for (int j = 0; j < (1 << (P - i - 1)); j++)
			scanf("%d", &a[start + j]);
	}
}

void compute(int i) {
	if (i >= n - 1) {
		int ii = i - (n - 1);
		for (int j = 0; j <= P; j++) {
			if (P - j <= limit[ii])
				c[i][j] = 0;
			else
				c[i][j] = oo;
		}
		return;
	}
	for (int j = 0; j <= P; j++) {
		if (c[i * 2 + 1][j] == oo || c[i * 2 + 2][j] == oo)
			c[i][j] = oo;
		else
			c[i][j] = c[i * 2 + 1][j] + c[i * 2 + 2][j];
		int j1 = min(j + 1, P);
		if (c[i * 2 + 1][j1] == oo || c[i * 2 + 2][j1] == oo)
			c[i][j] = min(c[i][j], oo);
		else
			c[i][j] = min(c[i][j], c[i * 2 + 1][j1] + c[i * 2 + 2][j1] + a[i]);
	}
}

void solve() {
	for (int i = n * 2 - 2; i >= 0; i--)
		compute(i);
}

void output() {
	printf("Case #%d: %d\n", I + 1, c[0][0]);
}

int main() {
	scanf("%d", &T);
	for (I = 0; I < T; I++) {
		input();
		solve();
		output();
	}
	return 0;
}

