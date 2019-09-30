#include <iostream>
using namespace std;
long long gcd(long long x, long long y) {
	if (y == 0) return x;
	return gcd(y, x % y);
}
int main() {
	int Q;
	cin >> Q;
	for (int i = 0; i < Q; ++i) {
		long long A, B, C, D;
		cin >> A >> B >> C >> D;
		bool ans = true;
		if (A < B || B > D) ans = false;
		else {
			long long g = gcd(B, D);
			long long tar = -1;
			if (B % g > A % g) tar = B / g * g + A % g;
			else tar = (B / g - 1) * g + A % g;
			if (tar > C) ans = false;
		}
		cout << (ans ? "Yes" : "No") << endl;
	}
	return 0;
}