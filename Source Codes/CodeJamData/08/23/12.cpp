#include <cstdio>
#include <cmath>
#include <cctype>
#include <cstring>

#include <iostream>

#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <utility>

using namespace std;

int a[2000000];
int d[1000];
int nx[2000000];

int b[2000000];

int N = 2000000;

#define nx(x) ((x) | ((x) + 1))
#define pr(x) ((x) & ((x) + 1))

inline int sum(int x) {
	int r = 0;
	while (x >= 0) {
		r += b[x];
		x = pr(x) - 1;
	}
	return r;
}

inline int sum(int l, int r) {
	return sum(r) - sum(l - 1);
}

inline void add(int x) {
	while (x < N) {
		++b[x];
		x = nx(x);
	}
}

inline void dec(int x) {
	while (x < N) {
		--b[x];
		x = nx(x);
	}
}

int main() {
	int T; scanf("%d", &T);
	for (int tt = 0; tt < T; ++tt) {
		int n, m; scanf("%d %d", &n, &m);
		N = n + 1;
		for (int i = 0; i < m; ++i) {
			scanf("%d", &d[i]);
		}
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(a));
		for (int i = 1; i <= n; ++i) {
			nx[i] = i + 1;
			add(i);
		}
		nx[n] = 1;
		int last = n;
		for (int i = 1; i <= n; ++i) {
			int z = i % (n - i + 1);
			if (z == 0) z = n - i + 1;
			int X = last;
			last = nx[last];
			while (a[last]) {
				last = nx[last];
			}
			if (last != nx[X]) nx[X] = last;
			int s = last;
			if (s > n) s = 1;
			int x = sum(s, n);
			if (x < z) {
				z -= x;
				s = 1;
			}
			int l = 0, r = n + 1;
			while (r - l > 1) {
				int y = (l + r) >> 1;
				if (sum(s, y) < z) l = y;
				else r = y;
			}
			last = r;
			dec(last);
			
		/*
			for (int k = 0; k < i; ++k) {
				int x = last;
				last = nx[last];
				while (a[last]) {
					last = nx[last];
				}
				if (last != nx[x]) nx[x] = last;
			}*/
			a[last] = i;
/*		for (int i = 1; i <= n; ++i) {
			cout << a[i] << " ";
		}
		cout << endl;*/
		}
/*		for (int i = 1; i <= n; ++i) {
			cout << a[i] << " ";
		}
		cout << endl;*/
		printf("Case #%d:", tt + 1);
		for (int i = 0; i < m; ++i) {
			printf(" %d", a[d[i]]);
		}
		cout << endl;
	}
	return 0;
}
