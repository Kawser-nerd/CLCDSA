#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<int> ip(N);
	for (int i = 0; i < N; ++i) {
		int x;
		cin >> x; --x;
		ip[x] = i;
	}
	int cont = 1, ans = 1;
	for (int i = 1; i < N; ++i) {
		if (ip[i - 1] < ip[i]) {
			++cont;
			ans = max(ans, cont);
		}
		else {
			cont = 1;
		}
	}
	cout << N - ans << endl;
	return 0;
}