#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int N, K;
	cin >> N >> K;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	int ret = 1 << 30;
	for (int i = K - 1; i < N; ++i) {
		ret = min(ret, A[i] - A[i - K + 1]);
	}
	cout << ret << endl;
	return 0;
}