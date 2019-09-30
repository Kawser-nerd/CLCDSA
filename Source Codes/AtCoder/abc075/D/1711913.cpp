#include <climits>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int countC(vector<pair<int, int>>& xy, int xbegin, int xend, int ybegin, int yend) {
	int c = 0;
	for (auto i : xy) {
		if (i.first >= xbegin && i.first <= xend && i.second >= ybegin && i.second <= yend) {
			c++;
		}
	}
	return c;
}

int main() {
	int n, k;
	cin >> n >> k;

	vector<pair<int, int>> xy(n);

	for (auto& i : xy) {
		int x, y;
		cin >> x >> y;
		i = make_pair(x, y);
	}

	sort(begin(xy), end(xy));


	long long ans = LLONG_MAX;

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			int ybegin = xy[i].second;
			int yend = xy[j].second;
			if (ybegin > yend) swap(ybegin, yend);
			if (countC(xy, INT_MIN, INT_MAX, ybegin, yend) < k) continue;

			long long yl = yend - ybegin;
			long long xl = xy[n - 1].first - xy[0].first;

			for (int ix = 0; ix < n - k + 1; ix++) {
			    int c = 0;
			    int ie = ix - 1;
				while (c < k && ie < n - 1) {
					ie++;
					if (xy[ie].second >= ybegin && xy[ie].second <= yend) c++;	
				}
				if (c >= k) {
					int xt = xy[ie].first - xy[ix].first;
					if (xl > xt) xl = xt;
				}
			}

			long long anst = xl * yl;
			if (ans > anst) ans = anst;
		}
	}
	cout << ans << endl;
	return 0;
}