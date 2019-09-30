#include <sstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cassert>
#include <ctime>
#include <map>
#include <math.h>
#include <cstdio>
#include <set>
#include <deque>
#include <memory.h>
#include <queue>

#pragma comment(linker, "/STACK:64000000")
typedef long long ll;

using namespace std;

const int MAXK = -1;
const int MAXN = -1;
const int MOD = 1; // 1000 * 1000 * 1000 + 7;
const int INF = (int)(1e9);


int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		cout << "Case #" << test << ": ";
		cerr << "Case #" << test << ": ";

		int n, m;
		cin >> n >> m;
		vector<int> r(n);
		for (int i = 0; i < n; i++) cin >> r[i];

		vector<vector<int> > a(n, vector<int>(m));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> a[i][j];
			}
		}

		const int MX = 1.5e6;
		/*vector<vector<int> > cnt(n, vector<int>(MX));
		auto ok = [&](int x, int y) {
			return 10 * x >= 9 * y && 10 * x <= 11 * y;
		};
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < p; j++) {
				//for (int k = 1; k <= (int)1e6; k++) {
				int L, R;
				L = -1, R = MX;
				while (R - L > 1) {
					int M = (L + R) >> 1;
					// max M: q[i][j] >= 0.9*M*r[i]
					if (q[i][j] * 10 >= M * 9LL * r[i]) L = M;
					else R = M;
				}
				int o1 = L;

				L = -1;
				R = MX;
				while (R - L > 1) {
					int M = (L + R) >> 1;
					// min M: q[i][j] <= 1.1*M*r[i]
					if (10 * q[i][j] <= 11LL * M * r[i]) R = M;
					else L = M;
				}

				int o2 = R;
				if (o2 <= o1) {
					cnt[i][o2]++;
					cnt[i][o1 + 1]--;
				}
				//}
			}
		}
		int ans = 0;
		
		for (int i = 0; i < n; i++) {
			for (int j = 1; j < MX; j++) cnt[i][j] += cnt[i][j - 1];
		}

		for (int i = 1; i < MX; i++) {
			int mn = 1e9;
			for (int j = 0; j < n; j++) mn = min(mn, cnt[j][i]);
			ans += mn;
		}*/

		int ans = 0;

		//vector<vector<char> > used(n, vector<char>(m));
		for (int i = 0; i < n; i++) sort(a[i].begin(), a[i].end());
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				// 10x >= 9k * r[i]
				// 10x <= 11k * r[i]
				a[i][j] *= 10;
			}
		}
		int maxR = -1;

		for (int i = 0; i < n; i++) maxR = max(maxR, r[i]);
		for (int k = 1; k < MX; k++) {
			if (1LL * k * maxR * 9 > 1.1e7) break;

			while (1) {
				vector<int> id;
				for (int i = 0; i < n; i++) {
					int cid = lower_bound(a[i].begin(), a[i].end(), 9 * k * r[i]) - a[i].begin();
					if (cid < (int)a[i].size() && a[i][cid] <= 11 * k * r[i]) {
						id.push_back(cid);
					}
					else {
						break;
					}
				}
				if (id.size() != n) break;
				ans++;
				for (int i = 0; i < n; i++) {
					a[i].erase(a[i].begin() + id[i]);
				}
			}
		}

		cout << ans << endl;
		cerr << ans << endl;
	}

	return 0;
}