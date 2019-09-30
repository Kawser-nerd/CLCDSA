#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <ctime>
#include <numeric>

using namespace std;

#define sqr(a) ((a)*(a))
#define two(a) (1 << (a))
#define has(mask, a) ((mask) & two(a) ? 1 : 0)

long long a[1000005], sum[1000005];
int n;

void load() {
	int p, q, r, s;
	cin >> n >> p >> q >> r >> s;
	for (int i = 0;i < n;i++) {
		a[i] = (i * 1ll * p + q) % r + s;
		sum[i] = (i == 0 ? a[i] : sum[i - 1] + a[i]);
	}
}

void solve(int test) {
	long long ans = 0;

	for (int i = 0;i < n;i++) {
		long long left = (i == 0 ? 0 : sum[i - 1]);

		int l = i, r = n;
		while (r - l > 1) {
			int mid = (l + r) / 2;

			long long cur = sum[mid] - (i == 0 ? 0 : sum[i - 1]);
			long long b = sum[n - 1] - sum[mid];
			if (cur > max (left, b)) {
				r = mid;
			} else {
				l = mid;
			}
		}

		long long cur = left;
		for (int j = l - 5;j <= l + 5;j++) {
			if (j < i || j >= n) continue;
			long long a = sum[j] - (i == 0 ? 0 : sum[i - 1]);
			long long b = sum[n - 1] - sum[j];
			long long c = max (a, max (cur, b));

			ans = max (ans, sum[n - 1] - c);
		}
	}

	printf ("Case #%d: %.10lf\n", test, (double)ans / sum[n - 1]);
}

int main() {
 	freopen ("a.in", "r", stdin);

 	int t;
 	scanf ("%d\n", &t);

 	for (int i = 1;i <= t;i++) {
 		load();
 		solve(i);
 	}

 	return 0;
}