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

int n; int a[N]; 
int v[N]; int s[N]; 

int main() {
	int _; cin >> _;
	for (int __ = 1; __ <= _; __ ++) {
		cin >> n;
		for (int i = 0; i < n; i ++) {
			cin >> a[i]; a[i] --; 
		}
		memset(v, 0, sizeof v);
		int S = 0; 
		for (int i = 0; i < n; i ++) 
			if (v[i] == 0) {
				int j = i;
				int u = 10000+i;
				while (v[j] != u && v[j] != 2) {
					v[j] = u; j = a[j];
				}
				if (v[j] == 2) continue;
				int l = 0; 
				while (v[j] == u) {
					v[j] = 2; j = a[j];
					l ++;
				}
				S = max(S, l);
			}
		memset(s, 0, sizeof s);
		for (int i = 0; i < n; i ++) 
			if (v[i] != 2) {
				int j = i; int l = 0; 
				while (v[j] != 2) {
					j = a[j]; l ++; 
				}
				s[j] = max(s[j], l);
			}
		int T = 0; 
		for (int i = 0; i < n; i ++) 
			if (a[a[i]] == i) T += s[i]+1; 
		S = max(S, T);
		printf ("Case #%d: %d\n", __, S);
	}
	return 0;
}
