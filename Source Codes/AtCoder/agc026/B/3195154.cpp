#include <iostream>
using namespace std;

#define int long long

int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a%b);
}

signed main() {
	int T;
	cin >> T;
	while (T--) {
		int A, B, C, D;
		cin >> A >> B >> C >> D;
		if (A < B || D < B) {
			cout << "No" << endl;
		} else if (C < B - (gcd(B, D) - A % gcd(B, D))) {
			cout << "No" << endl;
		} else {
			cout << "Yes" << endl;
		}
	}
}