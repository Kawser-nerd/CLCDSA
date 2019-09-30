#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long LL;
const LL INF = 1e18;
const int MAXN = 111111 * 2;
const int W = 9e8;
int n, E;
LL f[MAXN], minf[MAXN], x[MAXN], T, tr[MAXN << 2], a[MAXN], b[MAXN], p[MAXN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> p[i];
	for (int i = 1; i <= n; ++i) {
		a[i] = W / n * (i);
		b[i] = W / n * (n - i + 1);
	}
	for (int i = 1; i <= n; ++i) {
		b[p[i]] += i;
	}
	for (int i = 1; i < n; ++i) cout << a[i] << " ";
	cout << a[n] << endl;
	for (int i = 1; i < n; ++i) cout << b[i] << " ";
	cout << b[n] << endl;
}