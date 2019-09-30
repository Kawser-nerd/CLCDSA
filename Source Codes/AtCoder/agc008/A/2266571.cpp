#include<iostream>
#include<cmath>
using namespace std;
int main() {
	long long x, y; cin >> x >> y;
	long long ans = 0;
	if (abs(x) < abs(y)) {
		if (x < 0) {
			ans++;
			x = -x;
		}
		ans += abs(y) - abs(x);
		x += abs(y) - abs(x);
	}
	if (abs(x) > abs(y)) {
		if (x > 0) {
			ans++;
			x = -x;
		}
		ans += abs(x) - abs(y);
		x += abs(x) - abs(y);
	}
	if (x*y < 0)ans++;
	cout << ans << endl;
	return 0;
}