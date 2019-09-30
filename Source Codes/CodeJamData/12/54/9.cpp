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

const int maxN = 100;
int d[maxN][maxN];
int a[maxN], p[maxN], q[maxN], k, n;
string s;

void solve(int test) {
	cin >> k;
	cin >> s;
	n = s.size();
	memset(a, 0, sizeof(a));
	memset(d, 0, sizeof(d));
	memset(p, 0, sizeof(p));
	memset(q, 0, sizeof(q));

	for (int i = 0; i < maxN; ++i) {
		a[i] = -1;
	}

	a['o' - 'a'] = 26 + 0;
	a['i' - 'a'] = 26 + 1;
	a['e' - 'a'] = 26 + 2;
	a['a' - 'a'] = 26 + 3;
	a['s' - 'a'] = 26 + 4;
	a['t' - 'a'] = 26 + 5;
	a['b' - 'a'] = 26 + 6;
	a['g' - 'a'] = 26 + 7;

	for (int i = 1; i < n; ++i) {
		int x = s[i] - 'a', y = s[i - 1] - 'a';
		d[x][y] = 1;
		if (a[x] >= 0) {
			d[a[x]][y] = 1;
		}
		if (a[y] >= 0) {
			d[x][a[y]] = 1;
		}
		if (a[x] >= 0 && a[y] >= 0) {
			d[a[x]][a[y]] = 1;
		}
	}

	for (int i = 0; i < maxN; ++i) {
		for (int j = 0; j < maxN; ++j) {
			p[i] += d[i][j];
			q[j] += d[i][j];
		}
	}

	bool good = true;
	long long res = 0;
	for (int i = 0; i < maxN; ++i) {
		if (p[i] != q[i]) {
			good = false;
		}
	}

	for (int i = 0; i < maxN; ++i) {
		res += max(p[i], q[i]);
	}

	if (good) {
		++res;
	}

	cout << "Case #" << test << ": " << res << endl;
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