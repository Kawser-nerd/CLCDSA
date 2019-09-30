#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <ctime>
#include <cassert>
#include <cstring>

using namespace std;

#define sqr(a) ((a)*(a))
#define has(mask,a) (((mask) & (1 << (a))) ? 1 : 0)

int np, n, a[1 << 20];

void load() {
	cin >> np;
	n = 1 << np;
	for (int i = 0;i < n;i++) {
		cin >> a[i];
		a[i]--;
	}
}

long long fact (int st) {
	long long res = 1;
	for (int i = 1;i <= st;i++) {
		res *= i;
	}
	return res;
}

long long go (int k, int st) {
	if (k == -1) {
		for (int i = 1;i < n;i++) {
			if (a[i] != a[i - 1] + 1) return 0;
		}
		return fact (st);
	}

	int op[15];
	memset (op, 0, 15 * sizeof (int));
	for (int i = 0;i < n;i += (1 << k)) {
		int r = i + (1 << k);
		int q = 0;
		for (int j = i;j < r;j++) {
			if (a[j] < i || a[j] >= r) q++;
		}

		for (int j = k;j >= 0;j--) {
			if (has (q, j)) {
				q = j;
				break;
			}
			if (j == 0) q = -1;
		}
		if (q > 0) {
			op[q]++;
		}
	}

	/*for (int i = 0;i < n;i++) {
	    cerr << a[i] << " ";
	}
	cerr << endl;
	for (int i = 0;i <= k;i++) {
		cerr << op[i] << " ";
	}
	cerr << endl;
	cerr << endl; */

	for (int i = 0;i < k;i++) {
		while (op[i] > 2) {
			op[i] -= 2;
			op[i + 1]++;
		}
	}
	if (op[k] > 2) return 0;

	long long res = go (k - 1, st);
	for (int i = 0;i < n;i += (1 << k)) {
		for (int j = i + (1 << k);j < n;j += (1 << k)) {
			for (int q = 0;q < (1 << k);q++) {
				swap (a[i + q], a[j + q]);
			}	
			res += go (k - 1, st + 1);
			for (int q = 0;q < (1 << k);q++) {
				swap (a[i + q], a[j + q]);
			}
		}
	}
	return res;
}

void solve (int test) {
	printf ("Case #%d: %I64d\n", test, go (np - 1, 0));
}

int main() {
 	freopen ("a.in", "r", stdin);

 	int t;
 	scanf ("%d\n", &t);

 	for (int i = 0;i < t;i++) {
 		cerr << i << endl;
 		load();
 		solve(i + 1);
 	}
}
