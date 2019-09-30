#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	int N; cin >> N;
	vector<int>A(N);
	for (int i = 0; i < N; i++)cin >> A[i];

	long long cnt = 0;
	vector<char>used(20);
	int l=0, r;
	for (r = 0; r < N; r++) {
		bool flag = true;
		for (int j = 0; j < 20; j++)if (A[r] & 1 << j) if (used[j]) flag = false;
	
		if (flag) {
			for (int j = 0; j < 20; j++)if (A[r] & 1 << j)used[j] = true;
		}
		else {
			cnt += r - l;
			for (int j = 0; j < 20; j++)if (A[l] & 1 << j)used[j] = false;
			l++;
			r--;
		}
	}
	for (; l < N; l++)cnt += r - l;
	
	cout << cnt << endl;

	return 0;
}