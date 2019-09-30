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

const int N = 2000000 + 10;

int n, d;
int s[N], m[N];
int a[N], b[N];
int cnt[N];

void solve()
{
	cin >> n >> d;
	long long A, C, R;
	cin >> s[0] >> A >> C >> R;
	for(int i = 1; i < n; ++ i) {
		s[i] = (s[i - 1] * A + C) % R;
	}
	cin >> m[0] >> A >> C >> R;
	for(int i = 1; i < n; ++ i) {
		m[i] = (m[i - 1] * A + C) % R;
	}
	for(int i = 1; i < n; ++ i) {
		m[i] %= i;
	}

	memset(cnt, 0, sizeof cnt);

	a[0] = s[0]; b[0] = s[0] + d;
	vector<pair<int, int> > vec;
	for(int i = 1; i < n; ++ i) {
		a[i] = s[i]; b[i] = a[i] + d;
		a[i] = max(a[i], a[m[i]]);
		b[i] = min(b[i], b[m[i]]);
	}
	for(int i = 0; i < n; ++ i) {
		if (a[i] <= b[i]) {
			cnt[a[i]] ++;
			cnt[b[i] + 1] --;
		}
	}
	for(int i = 1; i < N; ++ i) {
		cnt[i] += cnt[i - 1];
	}
	int ret = 0;
	for(int i = 0; i < N; ++ i) {
		ret = max(ret, cnt[i]);
	}
	cout << ret << endl;
}

int main()
{
	//freopen("A-small-attempt0.in", "r", stdin); freopen("A-small-attempt0.out", "w", stdout);
	//freopen("A-small-attempt1.in", "r", stdin); freopen("A-small-attempt1.out", "w", stdout);
	freopen("A-large.in", "r", stdin); freopen("A-large.out", "w", stdout);
	int test_case;
	cin >> test_case;
	for(int i = 0; i < test_case; ++ i) {
		printf("Case #%d: ", i + 1);
		solve();
	}
	return 0;
}
