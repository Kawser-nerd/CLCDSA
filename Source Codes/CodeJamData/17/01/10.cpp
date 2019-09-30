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
		int k;
		cin >> k;
		int S = 0;
		for (int i = 0; i <= n-k; i ++)
			if (s[i] == '-') {
				S++;
				for (int j = i; j < i+k; j ++) 
					if (s[j] == '+') s[j] = '-';
					else s[j] = '+';
			}
		bool F = true;
		for (int i = 0; i < n; i ++)
			if (s[i] == '-') F = false;
		printf ("Case #%d: ", __);
		if (!F) puts ("IMPOSSIBLE");
		else cout << S << endl;
	}
	return 0;
}
