#include <vector>
#include <iostream>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<int> A(300);
	A[0] = N;
	for(int i = 1; i < 300; ++i) {
		if(A[i - 1] % 2 == 0) A[i] = A[i - 1] / 2;
		else A[i] = 3 * A[i - 1] + 1;
	}
	int ans = -1;
	for(int i = 1; i <= 300 && ans == -1; ++i) {
		for(int j = 0; j < i; ++j) {
			if(A[i] == A[j]) {
				ans = i;
			}
		}
	}
	cout << ans + 1 << endl;
	return 0;
}