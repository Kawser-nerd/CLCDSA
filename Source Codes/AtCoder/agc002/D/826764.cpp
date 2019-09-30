#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <iostream>
#include <sstream>
#include <cstring>
#include <numeric>
#include <ctime>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define F0(i,n) for (int i = 0; i < n; i++)
#define F1(i,n) for (int i = 1; i <= n; i++)
#define CL(a,x) memset(x, a, sizeof(x));
#define SZ(x) ((int)x.size())
const double eps = 1e-10;
const int inf = 1000000009;
int i, j, k, m, n, l;
const int M = 250;
const int N = 100001;
int a[N], b[N], x[N], y[N], z[N], sz[N], p[N], cand[N], ans[N];
vector<int> starts[N];

inline int find(int x) {
	while (p[x] != x) x = p[x]; return x;
}

int main() {
	//freopen("x.in", "r", stdin);
	
	scanf("%d%d", &n, &m);
	F0(i, m) scanf("%d%d", &a[i], &b[i]);
	scanf("%d", &k);
	F0(i, k) scanf("%d%d%d", &x[i], &y[i], &z[i]);
	/*
	n = 100000; m = 100000;
	F0(i, m) {
		a[i] = rand() % n + 1;
		b[i] = rand() % n + 1;
		if (i > 0) {
			a[i] = i + 1;
			b[i] = rand() % i + 1;
		}
	}
	k = 100000;
	F0(i, k) {
		x[i] = rand() % n + 1;
		y[i] = rand() % n + 1;
		z[i] = rand() % n + 1;
	}
	*/

	F1(i, n) {
		p[i] = i;
		sz[i] = 1;
	}

	F0(i, m) {
		int A = find(a[i]);
		int B = find(b[i]);
		if (A != B) {
			if (sz[A] < sz[B]) swap(A, B);
			p[B] = A;
			sz[A] += sz[B];
		}

		if (i == m - 1 || (i + 1) % M == 0) {
			F1(i, n) p[i] = find(p[i]);
			F0(j, k) if (!cand[j]) {
				int A = find(x[j]);
				int B = find(y[j]);
				int cnt = sz[A]; if (A != B) cnt += sz[B];
				if (cnt >= z[j]) {
					cand[j] = i + 1;
					starts[max(0, i - M)].push_back(j);
				}
			}
		}
	}


	F1(i, n) {
		p[i] = i;
		sz[i] = 1;
	}

	set<int> S;
	F0(i, m) {
		for (int j : starts[i]) S.insert(j);

		int A = find(a[i]);
		int B = find(b[i]);
		if (A != B) {
			if (sz[A] < sz[B]) swap(A, B);
			p[B] = A;
			sz[A] += sz[B];

			for (set<int>::iterator it = S.begin(); it != S.end(); ) {
				int j = *it;
				int A = find(x[j]);
				int B = find(y[j]);
				int cnt = sz[A]; if (A != B) cnt += sz[B];
				if (cnt >= z[j]) {
					ans[j] = i + 1;
					it = S.erase(it);
				}
				else it++;
			}
		}
		if (i == m - 1 || (i + 1) % M == 0) {
			F1(i, n) p[i] = find(p[i]);
		}


	}
	F0(i, k) printf("%d\n", ans[i]);
	return 0;
}