#include <iostream>
#include <algorithm>
using namespace std;

int a[51][51];
int v[2501];

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			scanf("%d", &a[i][j]);
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			a[i][j] += a[i][j - 1] + a[i - 1][j] - a[i - 1][j - 1];
			// cout << a[i][j] << (j == n ? "\n" : " ");
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = i + 1; k <= n; ++k) {
				for (int l = j + 1; l <= n; ++l) {
					int sz = (k - i) * (l - j);
					v[sz] = max(v[sz], a[k][l] + a[i][j] - a[i][l] - a[k][j]);
					// cout << sz << " " << v[sz] << endl;
				}
			}
		}
	}

	for (int i = 1; i < 2501; ++i) {
		v[i] = max(v[i], v[i - 1]);
	}

	int q;
	cin >> q;
	while (q--) {
		int p;
		cin >> p;

		cout << v[p] << endl;
	}
}