#include <iostream>
#include <algorithm>
#define N 2000000000000

using namespace std;

typedef long long ll;

int main() {
	ll a, k;
	cin >> a >> k;

	if (k == 0) {
		cout << N - a << endl;
		return 0;
	}

	int d = 0;
	for (d = 0; ; d++) {
		a += 1 + (k * a);
		if (a / N > 0) break;
	}

	cout << d + 1 << endl;
	return 0;
}