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

const int N = 25 + 1;
int n;
double y, ans;
double p[N], s[N];

void dfs(double cur, double now, int state)
{
	double it;
	for(int i = 0; i < n; ++ i) {
		if (state >> i & 1) continue;
		it = p[i] < 0 ? p[i] - s[i] * cur : p[i] + s[i] * cur;
		if (abs(it - now) < 1e-9) {
			state += 1 << i;
		}
	}

	if (state + 1 == (1 << n)) {
		ans = min(ans, cur);
		return;
	}

	{
		int id = -1;
		double it, far;
		for(int i = 0; i < n; ++ i) {
			if (state >> i & 1) continue;
			it = p[i] < 0 ? p[i] - s[i] * cur : p[i] + s[i] * cur;
			if (it > now) {
				double tmp = (it - now) / (y - s[i]);
				if (id < 0 || far > tmp) {
					id = i;
					far = tmp;
				}
			}
		}
		if (id >= 0) {
			dfs(cur + far, now + far * y, state + (1 << id));
		}
	}
	{
		int id = -1;
		double it, far;
		for(int i = 0; i < n; ++ i) {
			if (state >> i & 1) continue;
			it = p[i] < 0 ? p[i] - s[i] * cur : p[i] + s[i] * cur;
			if (it < now) {
				double tmp = (now - it) / (y - s[i]);
				if (id < 0 || far > tmp) {
					id = i;
					far = tmp;
				}
			}
		}
		if (id >= 0) {
			dfs(cur + far, now - far * y, state + (1 << id));
		}
	}
}

void solve()
{
	//y = 1000;
	//n = 22;
	cin >> y;
	cin >> n;
	for(int i = 0; i < n; ++ i) {
		cin >> p[i];
		//p[i] = rand() % 2000000 - 1000000;
	}
	for(int i = 0; i < n; ++ i) {
		cin >> s[i];
		//s[i] = rand() % (int)y + 1;
	}
	ans = 1e100;
	dfs(0, 0, 0);
	printf("%.16f\n", (double)ans);
}

int main()
{
	freopen("C-small-attempt0.in", "r", stdin); freopen("C-small-attempt0.out", "w", stdout);
	//freopen("C-small-attempt1.in", "r", stdin); freopen("C-small-attempt1.out", "w", stdout);
	//freopen("C-large.in", "r", stdin); freopen("C-large.out", "w", stdout);
	int test_case;
	cin >> test_case;
	for(int i = 0; i < test_case; ++ i) {
		cerr << i << endl;
		printf("Case #%d: ", i + 1);
		solve();
	}
	return 0;
}
