#include <vector>
#include <iostream>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	if (A[0] != 0) {
		cout << -1 << endl;
	}
	else {
		bool ok = true;
		long long ans = 0;
		for (int i = 1; i < N; ++i) {
			if (A[i] - A[i - 1] >= 2) {
				ok = false;
			}
			if (A[i - 1] >= A[i]) {
				ans += A[i - 1];
			}
		}
		ans += A[N - 1];
		cout << (ok ? ans : -1) << endl;
	}
	return 0;
}