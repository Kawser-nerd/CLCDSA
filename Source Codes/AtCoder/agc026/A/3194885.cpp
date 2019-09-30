#include <iostream>
using namespace std;

signed main() {
	int N;
	cin >> N;
	int last = -1, ans = 0;
	for (int i = 0; i < N; ++i) {
		int cur;
		cin >> cur;
		if (cur == last) {
			++ans;
			cur = -1;
		}
		last = cur;
	}
	cout << ans << endl;
}