#include <vector>
#include <iostream>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) cin >> A[i];
	long long L = 2, R = 2;
	for (int i = N - 1; i >= 0; --i) {
		L = (L + A[i] - 1) / A[i] * A[i];
		R = R / A[i] * A[i] + A[i] - 1;
		if (L > R) break;
	}
	if (L > R) cout << -1 << endl;
	else cout << L << ' ' << R << endl;
	return 0;
}