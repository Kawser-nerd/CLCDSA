#include <iostream>
#include <cmath>

using namespace std;
int main() {
	int n, k;
	cin >> n >> k;

	long long c = 0;
	for (int b = k+1; b <= n; b++) {
		c += (n / b) * max(0, b - k) + max(0, n % b - k + 1);
	}
	if (k == 0) c -= n;

	cout << c << endl;
	return 0;
}