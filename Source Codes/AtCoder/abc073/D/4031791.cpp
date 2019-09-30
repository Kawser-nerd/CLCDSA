#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 1012345678;
int main() {
	int N, M, R;
	cin >> N >> M >> R;
	vector<int> r(R);
	for (int i = 0; i < R; ++i) {
		cin >> r[i]; --r[i];
	}
	vector<vector<int> > d(N, vector<int>(N, inf));
	for (int i = 0; i < N; ++i) {
		d[i][i] = 0;
	}
	for (int i = 0; i < M; ++i) {
		int A, B, C;
		cin >> A >> B >> C; --A, --B;
		d[A][B] = C;
		d[B][A] = C;
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < N; ++k) {
				d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
			}
		}
	}
	sort(r.begin(), r.end());
	int ans = inf;
	do {
		int cost = 0;
		for (int i = 1; i < R; ++i) {
			cost += d[r[i - 1]][r[i]];
		}
		ans = min(ans, cost);
	} while (next_permutation(r.begin(), r.end()));
	cout << ans << endl;
	return 0;
}