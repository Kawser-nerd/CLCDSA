#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define N 110
int n, m;
int a[N];

multiset<PII> A[N];

int main() {
	int _;
	cin >> _;
	for (int __ = 1; __ <= _; __ ++) {
		cin >> n >> m;
		for (int i = 0; i < n; i ++) cin >> a[i];
		for (int i = 0; i < n; i ++) A[i].clear();
		for (int i = 0; i < n; i ++)
			for (int j = 0; j < m; j ++) {
				int x;
				cin >> x;
				int ri = 10*x/(9*a[i]);
				int le = (10*x-1)/(11*a[i])+1;
				A[i].insert(mp(le, ri));
			}
		int S = 0;
		while (true) {
			bool F = true;
			for (int i = 0; i < n; i ++)
				if (A[i].empty()) F = false;
			if (!F) break;
			int mle = 0;
			for (int i = 0; i < n; i ++)
				if (*A[i].begin() < *A[mle].begin())
					mle = i;
			int le = A[mle].begin()->fi;
			int ri = A[mle].begin()->se;
			for (int i = 0; i < n; i ++) {
				le = max(le, A[i].begin()->fi);
				ri = min(ri, A[i].begin()->se);
			}
			if (le <= ri) {
				S++;
				for (int i = 0; i < n; i ++)
					A[i].erase(A[i].begin());
			} else {
				A[mle].erase(A[mle].begin());
			}
		}
		printf ("Case #%d: %d\n", __, S);
	}
	return 0;
}