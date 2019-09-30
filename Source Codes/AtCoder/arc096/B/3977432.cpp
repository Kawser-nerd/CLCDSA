#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int N; long long C;
	cin >> N >> C;
	vector<long long> X(N), V(N);
	for (int i = 0; i < N; ++i) {
		cin >> X[i] >> V[i];
	}
	long long ans = -1;
	for (int i = 0; i < 2; ++i) {
		vector<long long> sl(N + 1), sr(N + 1);
		for (int j = 0; j < N; ++j) {
			sl[j + 1] = sl[j] + V[j] - (X[j] - (j == 0 ? 0 : X[j - 1]));
		}
		for (int j = N - 1; j >= 0; --j) {
			sr[j] = sr[j + 1] + V[j] - ((j == N - 1 ? C : X[j + 1]) - X[j]) * 2;
		}
		for (int j = 0; j < N; ++j) {
			sl[j + 1] = max(sl[j + 1], sl[j]);
		}
		for (int j = N - 1; j >= 0; --j) {
			sr[j] = max(sr[j], sr[j + 1]);
		}
		for (int j = 0; j <= N; ++j) {
			ans = max(ans, sl[j] + sr[j]);
		}
		reverse(X.begin(), X.end());
		reverse(V.begin(), V.end());
		for (int j = 0; j < N; ++j) {
			X[j] = C - X[j];
		}
	}
	cout << ans << endl;
	return 0;
}