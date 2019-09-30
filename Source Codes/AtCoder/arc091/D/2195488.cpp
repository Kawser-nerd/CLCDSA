#include <iostream>
using namespace std;

int grundy(int n, int k) {
	if (n % k == 0) return n / k;
	int a = n / k;
	int b = n % k;
	return grundy(n - ((b + a) / (a + 1)) * (a + 1), k);
}

int main() {
	int n, a, k, i;
	cin >> n;
	
	int x = 0;
	for (i = 0; i < n; i++) {
		cin >> a >> k;
		x ^= grundy(a, k);
	}
	if (x == 0) cout << "Aoki" << endl;
	else cout << "Takahashi" << endl;
	return 0;
}