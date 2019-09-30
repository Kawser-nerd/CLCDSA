#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define int long long
using namespace std;
bool b[20];
bool f(int k) {
	while (k > 0) {
		int p = k % 10;
		k /= 10;
		if (b[p])return 0;
	}return 1;
}
signed main() {
	int n, k; cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int p; cin >> p;
		b[p] = 1;
	}
	for (;; n++) {
		if (f(n)) {
			cout << n << endl;
			return 0;
		}
	}
}