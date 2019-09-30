#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<int> A(N), B(N);
	for (int i = 0; i < N; ++i) cin >> A[i];
	for (int i = 0; i < N; ++i) cin >> B[i];
	for (int i = 1; i < N; ++i) A[i] += A[i - 1];
	for (int i = N - 2; i >= 0; --i) B[i] += B[i + 1];
	int ret = 0;
	for (int i = 0; i < N; ++i) ret = max(ret, A[i] + B[i]);
	cout << ret << endl;
	return 0;
}