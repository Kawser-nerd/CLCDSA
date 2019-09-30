#include <cmath>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <climits>
#include <cstring>
#include <vector>
#include <string>
#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

#define foreach(e,x) for(__typeof((x).begin()) e=(x).begin(); e!=(x).end(); ++e)

const long long N = 1000 + 10;

long long n, k;
long long a[N];
long long r[N];

void solve()
{
	cin >> n >> k;
	for(long long i = 0; i < n - k + 1; ++ i) {
		scanf("%lld", a + i);
	}
	long long sum = 0;
	for(long long i = 0; i < k; ++ i) {
		long long maxv = 0, minv = 0;
		long long cur = 0;
		for(long long j = i + k; j < n; j += k) {
			cur += a[j - k + 1] - a[j - k];
			maxv = max(maxv, cur);
			minv = min(minv, cur);
		}
		r[i] = maxv - minv;
		sum -= minv;
	}
	sum = ((a[0] - sum) % k + k) % k;
	long long ans = 0;
	for(long long i = 0; i < k; ++ i) {
		ans = max(ans, r[i]);
	}
	long long go = 0;
	for(long long i = 0; i < k; ++ i) {
		go += ans - r[i];
	}
	if (go < sum) {
		++ ans;
	}
	cout << ans << endl;
}

int main()
{
	//freopen("B-small-attempt0.in", "r", stdin); freopen("B-small-attempt0.out", "w", stdout);
	//freopen("B-small-attempt1.in", "r", stdin); freopen("B-small-attempt1.out", "w", stdout);
	freopen("B-large.in", "r", stdin); freopen("B-large.out", "w", stdout);
	int test_case;
	cin >> test_case;
	for(int i = 0; i < test_case; ++ i) {
		printf("Case #%d: ", i + 1);
		solve();
	}
	return 0;
}
