#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int N; long long K;
	cin >> N >> K;
	vector<int> c(50);
	long long ans = 0;
	for (int i = 0; i < N; ++i) {
		long long x;
		cin >> x;
		for (int j = 49; j >= 0; --j) {
			if ((x >> j) & 1) ++c[j];
		}
		ans += x ^ K;
	}
	for (int i = 49; i >= 0; --i) {
		if ((K >> i) & 1) {
			long long sum = (long long)(c[i]) << i;
			for (int j = 0; j < i; ++j) {
				sum += (long long)max(c[j], N - c[j]) << j;
			}
			for (int j = i + 1; j <= 49; ++j) {
				if ((K >> j) & 1) {
					sum += (long long)(N - c[j]) << j;
				}
				else {
					sum += (long long)(c[j]) << j;
				}
			}
			ans = max(ans, sum);
		}
	}
	cout << ans << endl;
	return 0;
}