#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pct __builtin_popcount

#define N 1010

bool v[N]; 

int main() {
	int _; cin >> _;
	for (int __ = 1; __ <= _; __ ++) {
		string s; cin >> s;
		int n = (int) s.length();
		memset(v, 0, sizeof v); 
		int la = n;
		for (char c = 'Z'; c >= 'A'; c --) {
			int cur = la; 
			for (int i = 0; i < la; i ++) 
				if (s[i] == c) {
					cur = min(cur, i); 
					v[i] = 1; 
				}
			la = cur; 
		}
		string t;
		for (int i = 0; i < n; i ++) 
			if (v[i]) t = string(1, s[i]) + t;
			else t = t + string(1, s[i]);
		printf ("Case #%d: %s\n", __, t.c_str());
	}
	return 0;
}
