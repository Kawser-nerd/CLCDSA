//f(t, a) (t??) : ____/----?????????, (__??b, --??c, __????d, --????e)????????.
#include <iostream>
#include <algorithm>
#define int long long
using namespace std;

int x;
int k;
int r[100001];
int q;
int t[100000], a[100000];

int h(int i) {
	if (i & 1) return -1;
	return 1;
}

signed main() {
	int i;
	cin >> x >> k;
	for (i = 1; i <= k; i++) cin >> r[i];
	
	int b = 0, c = x, d = 0, e = x, j = 1;
	cin >> q;
	for (i = 0; i < q; i++) {
		cin >> t[i] >> a[i];
		for (; j <= k && r[j] <= t[i]; j++) {
			if (h(j) == -1) d = d + max(0LL, r[j] - r[j - 1] - b);
			b = min(x, max(0LL, b + h(j) * (r[j] - r[j - 1])));
			c = min(x, max(0LL, c + h(j) * (r[j] - r[j - 1])));
			e = d + (c - b);
		}
		
		int ans;
		if (a[i] <= d) ans = b;
		else if (a[i] <= e) ans = b + (a[i] - d);
		else ans = c;
		ans = min(x, max(0LL, ans + h(j) * (t[i] - r[j - 1])));
		cout << ans << endl;
	}
	return 0;
}