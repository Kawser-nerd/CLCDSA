#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pct __builtin_popcount

#define rep(i,l,r) for (int i=(l); i<=(r); i++)
#define repd(i,r,l) for (int i=(r); i>=(l); i--)
#define rept(i,c) for (__typeof((c).begin()) i=((c).begin()); i!=((c).end()); i++)

int main() {
	int _;
	cin >> _;
	for (int __ = 1; __ <= _; __ ++) {
		string s;
		cin >> s;
		int n = (int) s.length();
		printf ("Case #%d: ", __);
		if (string(n, '1') > s) {
			cout << string(n-1, '9') << endl;
			continue;
		}
		string t;
		for (int i = 0; i < n; i ++)
			for (int j = 9; j >= 0; j--) 
				if (t + string(n-i, (char)('0'+j)) <= s) {
					t += (char)('0'+j);
					break;
				}
		cout << t << endl;
	}
	return 0;
}
