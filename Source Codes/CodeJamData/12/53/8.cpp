#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 500;
const int maxS = 2100000;

long long n, m, f;
long long p[maxN], s[maxN];
long long a[maxS];
long long d[maxS];

bool check(long long key, long long i) {
	long long x = key / i;
	long long y = key % i;

	if (x > m) {
		return false;
	}
	long long cost = (i - y) * d[x - 1] + y * d[x];
	return cost + i * f <= m;
}

void solve(int test) {
	cin >> m >> f >> n;
	for (int i = 0; i < maxS; ++i) {
		a[i] = 1000000000LL;
	}
	for (int i = 1; i <= n; ++i) {
		cin >> p[i] >> s[i];
		a[s[i]] = min(a[s[i]], p[i]);
	}
	for (int i = 0; i <= m; ++i) {
		d[i] = -1;
	}

	for (int i = maxS - 2; i >= 0; --i) {
		a[i] = min(a[i + 1], a[i]);
	}

	d[0] = a[0];
	for (int i = 1; i < maxS; ++i) {
		d[i] = d[i - 1] + a[i];
		if (d[i] > m) {
			d[i] = m + 1; 
		}
	}

	long long res = 0;
	for (long long i = 1; i < maxS; ++i) {
		if ((long long)(i) * (long long)(f) > m) {
			break;
		}

		long long l = i, r = 1000000000LL;
		while (r - l > 1LL) {
			long long key = (l + r) / 2;

			if (check(key, i)) {
				l = key;
			} else {
				r = key;
			}
		}
		if (check(l, i)) {
			res = max(res, l);
		}
		if (check(r, i)) {
			res = max(res, r);
		}
	}
	//long long res = calc(m);

	/*long long res = 0;
	while (true) {
		long long left = m;
		left -= f;
		int last_one = -1;
		for (int i = 0; i < maxS; ++i) {
			if (left - a[i] >= 0) {
				last_one = i;
				left -= a[i];
			} else {
				break;
			}
		}
		if (last_one == -1) {
			break;
		}
		res += last_one + 1;
		m = left;
	}*/
	printf("Case #%d: %lld\n", test, res);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tests;
	scanf("%d", &tests);
	for (int i = 0; i < tests; ++i) {
		solve(i + 1);
		cerr << i << endl;
	}
	return 0;
}