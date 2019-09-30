#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
const double pi = acos(-1.0);

int main() {
	int a, n, tc;

	freopen("problem_a.in", "r", stdin);
	freopen("problem_a.out", "w", stdout);
	
	scanf("%d", &tc);
	for (int tnum = 0; tnum < tc; tnum++) {
		scanf("%d%d", &a, &n);
		vector <int> h;
		int d;
		for (int i = 0; i < n; i++) {
			scanf("%d", &d);
			h.pb(d);
		}

		sort(h.begin(), h.end());
		int ans = h.size();
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (a == 1)
				break;
			ans = min(ans, cnt + n - i);
			while (h[i] >= a) {
				a += a - 1;
				cnt++;
			}
			a += h[i];
		}
		if (a != 1)
			ans = min(ans, cnt);

		printf("Case #%d: %d\n", tnum + 1, ans);
	}

	return 0;
}