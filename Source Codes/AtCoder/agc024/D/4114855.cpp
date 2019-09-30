#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<int> a(N - 1), b(N - 1);
	vector<vector<int> > G(N);
	for (int i = 0; i < N - 1; ++i) {
		cin >> a[i] >> b[i]; --a[i], --b[i];
		G[a[i]].push_back(b[i]);
		G[b[i]].push_back(a[i]);
	}
	function<int(int, int)> dist = [&](int pos, int pre) {
		int ans = 0;
		for (int i : G[pos]) {
			if (i == pre) continue;
			ans = max(ans, dist(i, pos) + 1);
		}
		return ans;
	};
	function<void(int, int, int, vector<int>&)> calc = [&](int pos, int pre, int depth, vector<int> &v) {
		int cnt = 0;
		for (int i : G[pos]) {
			if (i == pre) continue;
			calc(i, pos, depth + 1, v);
			++cnt;
		}
		v[depth] = max(v[depth], cnt);
	};
	vector<int> d(N), de(N - 1);
	for (int i = 0; i < N; ++i) {
		d[i] = dist(i, -1);
	}
	for (int i = 0; i < N - 1; ++i) {
		de[i] = max(dist(a[i], b[i]), dist(b[i], a[i]));
	}
	int md = *min_element(d.begin(), d.end());
	md = min(md, *min_element(de.begin(), de.end()));
	long long ans = 1LL << 62;
	for (int i = 0; i < N; ++i) {
		if (d[i] != md) continue;
		vector<int> v(md + 1);
		calc(i, -1, 0, v);
		long long mul = 1;
		for (int i = 0; i < md; ++i) {
			mul *= v[i];
		}
		ans = min(ans, mul);
	}
	for (int i = 0; i < N - 1; ++i) {
		if (de[i] != md) continue;
		vector<int> v(md + 1);
		calc(a[i], b[i], 0, v);
		calc(b[i], a[i], 0, v);
		long long mul = 2;
		for (int i = 0; i < md; ++i) {
			mul *= v[i];
		}
		ans = min(ans, mul);
	}
	cout << md + 1 << ' ' << ans << endl;
	return 0;
}