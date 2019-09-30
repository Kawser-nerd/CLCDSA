#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int N; long long A, B, C, D;
	cin >> N >> A >> B >> C >> D;
	bool ok = false;
	for (int i = 0; i <= N - 1; ++i) {
		long long la = A + i * C, ra = A + i * D;
		long long lb = B + (N - i - 1) * C, rb = B + (N - i - 1) * D;
		if (max(la, lb) <= min(ra, rb)) {
			ok = true;
		}
	}
	cout << (ok ? "YES" : "NO") << endl;
	return 0;
}