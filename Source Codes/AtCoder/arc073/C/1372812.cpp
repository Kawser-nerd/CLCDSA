#include<iostream>
#include<cstdio>
#include<string>
#include<string.h>
#include<functional>
#include<algorithm>
#include<math.h>
#include<unordered_map>
#include<string.h>
#include<limits.h>
#include<list>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<unordered_set>
#include<deque>
#define int long long
#define P pair<int,int>
using namespace std;

P a[200000];
signed main() {
	int b; scanf("%lld", &b);
	for (int c = 0; c < b; c++) {
		scanf("%lld%lld", &a[c].first, &a[c].second);
	}
	int ans = LLONG_MAX / 3;
	if (1) {
		int n, m, x, y; n = x = 0; m = y = LLONG_MAX/3;
		for (int i = 0; i < b; i++) {
			if (a[i].first > a[i].second) {
				swap(a[i].first, a[i].second);
			}
			n = max(n, a[i].first);
			m = min(m, a[i].first);
			x = max(x, a[i].second);
			y = min(y, a[i].second);
		}
		ans = (x - y)*(n - m);
	}
	map<int, int>M, X;
	for (int i = 0; i < b; i++) {
		M[a[i].first]++;
		X[a[i].second]++;
	}
	sort(a, a + b);
	for (int i = 0; i < b; i++) {
		M[a[i].first]--;
		if (M[a[i].first] == 0) {
			M.erase(a[i].first);
		}
		X[a[i].second]--;
		if (X[a[i].second] == 0) {
			X.erase(a[i].second);
		}
		M[a[i].second]++;
		X[a[i].first]++;
		P S = *M.rbegin(),T=*M.begin();
		P p = *X.rbegin(), q = *X.begin();
		ans = min(ans, (p.first-q.first)*(S.first-T.first));
	}
	cout << ans << endl;
}