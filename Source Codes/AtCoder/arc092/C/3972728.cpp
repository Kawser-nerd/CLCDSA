#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const long long inf = 1234567891234567891;
int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) cin >> A[i];
	long long score = -inf; vector<int> v;
	for (int i = 0; i <= 1; ++i) {
		vector<long long> dp(N, -inf);
		for (int j = i; j < N; j += 2) {
			dp[j] = A[j];
			for (int k = j - 2; k >= 0; k -= 2) {
				dp[j] = max(dp[j], dp[k] + A[j]);
			}
		}
		vector<int> path;
		int ptr = N;
		while (true) {
			ptr = max_element(dp.begin(), dp.begin() + ptr) - dp.begin();
			path.push_back(ptr);
			if (dp[ptr] == A[ptr]) break;
		}
		if (score < *max_element(dp.begin(), dp.end())) {
			score = *max_element(dp.begin(), dp.end());
			reverse(path.begin(), path.end());
			v = path;
		}
	}
	vector<int> ops;
	for (int i = N - 1; i > v.back(); --i) {
		ops.push_back(i);
	}
	for (int i = int(v.size()) - 2; i >= 0; --i) {
		for (int j = v[i] + 2; j < v[i + 1]; j += 2) {
			ops.push_back(v[i] + 2);
		}
		ops.push_back(v[i] + 1);
	}
	for (int i = 0; i < v.front(); ++i) {
		ops.push_back(0);
	}
	cout << score << endl;
	cout << ops.size() << endl;
	for (int i : ops) {
		cout << i + 1 << endl;
	}
	return 0;
}