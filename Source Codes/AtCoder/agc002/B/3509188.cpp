#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<int> x;
	vector<int> y;
	vector<int> num;
	vector<int> red;
	x.resize(M + 10);
	y.resize(M + 10);
	num.resize(N + 10);
	red.resize(N + 10);
	for (int n = 0; n < N; ++n) {
		num[n] = 1;
		red[n] = 0;
	}
	red[0] = 1;
	int j = 0;
	for (int n = 0; n < M; ++n) {
		cin >> x[n] >> y[n];
		x[n] = x[n] - 1;
		y[n] = y[n] - 1;
		if (red[x[n]] == 1) {
			red[y[n]] = 1;
		}
		num[x[n]] -= 1;
		num[y[n]] += 1;
		if (num[x[n]] == 0) {
			red[x[n]] = 0;
		}
	}
	for (int k = 0; k < N; ++k) {
		if (red[k])++j;
	}
	cout << j << endl;
	return 0;
}