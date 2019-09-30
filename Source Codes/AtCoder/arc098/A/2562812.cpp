#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	int N; cin >> N;
	vector<int>sumW(N + 1), sumE(N + 1);
	vector<int>D(N);
	for (int i = 0; i < N; i++) {
		char c; cin >> c;
		if (c == 'W')D[i] = 1;
	}
	for (int i = 0; i < N; i++) {
		if (D[i]) {
			sumW[i + 1] += sumW[i] + 1;
			sumE[i + 1] += sumE[i];
		}
		else {
			sumE[i + 1] += sumE[i] + 1;
			sumW[i + 1] += sumW[i];
		}
	}

	int cnt = 1e9;
	for (int i = 0; i < N; i++) {
		int tmp = sumW[i] - sumW[0] + sumE[N] - sumE[i+1];
		cnt = min(cnt, tmp);
	}
	cout << cnt << endl;
	
	return 0;
}