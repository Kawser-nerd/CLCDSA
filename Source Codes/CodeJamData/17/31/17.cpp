#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
typedef pair<int, int> pii;

#define fi first
#define se second

double PI = acos(-1);
int n, k;
pii arr[N];

void read() {
	scanf("%d %d", &n, &k);
	for(int i = 0 ; i < n ; i++) {
		scanf("%d %d", &arr[i].fi, &arr[i].se);
	}
}

double solve() {
	sort(arr, arr + n);
	double ans = 0;
	long long mul = 0;
	priority_queue<long long> pq;

	for(int i = 0 ; i < n ; i++) {
		if(i+1 >= k) {
			double area = PI * arr[i].fi * arr[i].fi;
			area += 2 * PI * (mul + 1ll * arr[i].fi * arr[i].se);

			ans = max(ans, area); 
		}

		long long add = 1ll * arr[i].first * arr[i].second;
		mul += add;

		pq.push(-add);
		while(pq.size() > k-1) {
			mul += pq.top();
			pq.pop();
		}
	}

	return ans;
}

int main() {
	int t; cin >> t;
	for(int tc = 1 ; tc <= t ; tc++) {
		read();
		double ret = solve();
		printf("Case #%d: %.9lf\n", tc, ret);
	}
	return 0;
}