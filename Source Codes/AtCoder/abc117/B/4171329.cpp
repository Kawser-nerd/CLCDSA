#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<int> L(N);
	for (int i = 0; i < N; ++i) {
		cin >> L[i];
	}
	int sum = 0, mx = 0;
	for (int i = 0; i < N; ++i) {
		sum += L[i];
		mx = max(mx, L[i]);
	}
	sum -= mx;
	cout << (mx < sum ? "Yes" : "No") << endl;
	return 0;
}