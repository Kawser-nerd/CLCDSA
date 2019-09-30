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

int main () {
	int _; cin >> _;
	for (int __ = 1; __ <= _; __ ++) {
		string s; cin >> s;
		int n = (int) s.length();
		int S = 0;
		for (int i = 1; i < n; i ++) {
			if (s[i] != s[i-1]) S ++;
		}
		if (s[n-1] == '-') S ++;
		printf ("Case #%d: %d\n", __, S);
	}
	return 0;
}