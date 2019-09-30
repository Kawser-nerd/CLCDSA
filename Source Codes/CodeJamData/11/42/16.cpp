#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#define pb push_back
#define mp make_pair
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

template<class T> T abs(T a) {return a > 0 ? a : (-a); }
template<class T> T sqr(T a) {return a * a; }

using namespace std;

const int MAXN = 510;
int n, m;

long long a[MAXN][MAXN];
long long v[MAXN][MAXN], h[MAXN][MAXN], sum[MAXN][MAXN];

long long getHSum(int i1, int j1, int i2, int j2) {
	long long ans = h[i2][j2];
	if (i1 != 0) ans -= h[i1 - 1][j2];
	if (j1 != 0) ans -= h[i2][j1 - 1];
	if (i1 != 0 && j1 != 0) ans += h[i1 - 1][j1 - 1];
	return ans;
}

long long getVSum(int i1, int j1, int i2, int j2) {
	long long ans = v[i2][j2];
	if (i1 != 0) ans -= v[i1 - 1][j2];
	if (j1 != 0) ans -= v[i2][j1 - 1];
	if (i1 != 0 && j1 != 0) ans += v[i1 - 1][j1 - 1];
	return ans;
}

long long getSum(int i1, int j1, int i2, int j2) {
	long long ans = sum[i2][j2];
	if (i1 != 0) ans -= sum[i1 - 1][j2];
	if (j1 != 0) ans -= sum[i2][j1 - 1];
	if (i1 != 0 && j1 != 0) ans += sum[i1 - 1][j1 - 1];
	return ans;
}

bool is_good(int i, int j, int d) {
	long long H = getHSum(i, j, i + d - 1, j + d - 1) - 2 * j * (a[i][j] + a[i + d - 1][j]) - 2 * (j + d - 1) * (a[i][j + d - 1] + a[i + d - 1][j + d - 1]);
	long long V = getVSum(i, j, i + d - 1, j + d - 1) - 2 * i * (a[i][j] + a[i][j + d - 1]) - 2 * (i + d - 1) * (a[i + d - 1][j] + a[i + d - 1][j + d - 1]);
//	printf("%d %d\n", n, m);
//	for (int i = 0; i < n; ++i) {
//		for (int j = 0; j < m; ++j) printf("%d ", a[i][j]);
//		printf("\n");
//	}
	long long needH = (getSum(i, j, i + d - 1, j + d - 1) - a[i][j] - a[i][j + d - 1] - a[i + d - 1][j] - a[i + d - 1][j + d - 1]) * (2 * j + d - 1);
	long long needV = (getSum(i, j, i + d - 1, j + d - 1) - a[i][j] - a[i][j + d - 1] - a[i + d - 1][j] - a[i + d - 1][j + d - 1]) * (2 * i + d - 1);
//	printf("%d %d\n", H, V);
//	printf("%d %d\n", needH, needV);
	return (needH == H && needV == V);

}

void solve(int testnum) {
	cerr << testnum << endl;
	int d;
	scanf("%d%d%d", &n, &m, &d);
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < m; ++j) {
			int x = s[j] - '0';
			a[i][j] = x;
			v[i][j] = 2 * i * x;
			h[i][j] = 2 * j * x;
			sum[i][j] = x;
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (j != 0) {
				h[i][j] += h[i][j - 1];
				v[i][j] += v[i][j - 1];
				sum[i][j] += sum[i][j - 1];
			}
		}
		if (i != 0)
			for (int j = 0; j < m; ++j) {
				h[i][j] += h[i - 1][j];
				v[i][j] += v[i - 1][j];
				sum[i][j] += sum[i - 1][j];
			}
	}
	for (int D = n + m; D >= 3; --D) {
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (i + D <= n && j + D <= m && is_good(i, j, D)) {
					printf("Case #%d: %d\n", testnum, D);
					return;
				}
	}
	printf("Case #%d: IMPOSSIBLE\n", testnum);
}

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) solve(i + 1);
	return 0;
}
