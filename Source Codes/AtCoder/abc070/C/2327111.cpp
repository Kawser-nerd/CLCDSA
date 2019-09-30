#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <algorithm>

using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
	if (b == 0) {
		return a;
	}
	return gcd(b,a % b);
}

ll lcm(ll a, ll b) {
	ll g = gcd(a,b);
	return a / g * b;
}

int main() {
	int N;
	cin >> N;

	ll ans = 1LL;

	for (int i = 0; i < N; i++) {
		ll T;
		cin >> T;
		ans = lcm(ans, T);
	}

	cout << ans << endl;
	return 0;
}