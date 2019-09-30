#include <iostream>
using namespace std;
int main() {
	int N, K;
	cin >> N >> K;
	long long ans = 0;
	for (int i = K + 1; i <= N; ++i) {
		int sub = (N + 1) / i * (i - K);
		if ((N + 1) % i >= K) {
			sub += (N + 1) % i - K;
		}
		ans += sub;
		if (K == 0) --ans;
	}
	cout << ans << endl;
	return 0;
}