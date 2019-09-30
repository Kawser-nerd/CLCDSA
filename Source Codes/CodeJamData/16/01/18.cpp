#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;
typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pct __builtin_popcount

#define INF 1000000007
#define N 110

int ff(ll m) {
	int s = 0;
	while (m != 0) {
		s |= (1 << (m%10));
		m /= 10;
	}
	return s;
}

int main () {
	int _; cin >> _;
	for (int __ = 1; __ <= _; __ ++) {
		int n; cin >> n;
		printf ("Case #%d: ", __);
		if (n == 0) {
			puts ("INSOMNIA");
			continue;
		}
		ll m = n;
		int s = ff(m);
		while (s != 1023) {
			m += n;
			s |= ff(m);
		}
		printf ("%I64d\n", m);
	}
	return 0;
}