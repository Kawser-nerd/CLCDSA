#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;

const int nmax = 500000;
int s[nmax], t[nmax];
const int size = 1 << 19, mod = 1000000007;
int a[2 * size];
const bool debug = false;

int sum(int x) {
	int r = 0;
	
	for (x += size; x > 1; x >>= 1) {
		if (!(x & 1)) r = (r + a[x + 1]) % mod;
	}
	
	return r;
}

int ins(int x, int s) {
	for (x += size; x; x >>= 1) {
		a[x] = (a[x] + s) % mod;
	}
}

int main() {
	int nt, it;
	
	cin >> nt;
	for (it = 1; it <= nt; it++) {
		int n, m, x, y, z, a[100], i;
		map<int, int> e;
		
		cin >> n >> m >> x >> y >> z;
		for (i = 0; i < m; i++) cin >> a[i];
		for (i = 0; i < n; i++) {
			t[i] = s[i] = a[i % m];
			if (debug) cout << i << ": " << s[i] << '\n';
			a[i % m] = (ll(x) * a[i % m] + ll(y) * (i + 1)) % z;
		}
		
		sort(t, t + n);
		for (i = 0; i < n; i++) e[t[i]] = i + 1;
		
//		fill(a, a + 2 * size, 0);
		memset(::a, 0, sizeof ::a);
		for (i = n - 1; i >= 0; i--) {
			if (debug) cout << "sum(" << e[s[i]] << " = e[" << s[i] << "]) = " << sum(e[s[i]]) << '\n';
			ins(e[s[i]], 1 + sum(e[s[i]]));
		}
		
		cout << "Case #" << it << ": " << sum(0) << '\n';
	}
	
	return 0;
}
