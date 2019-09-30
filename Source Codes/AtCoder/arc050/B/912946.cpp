#include <iostream>

using namespace std;
using ll = long long;
constexpr ll TEN(int n) {return (n==0) ? 1 : 10*TEN(n-1);}

int main() {
	ll R, B, x, y;
	cin >> R >> B >> x >> y;
	ll l = 0, r = min(R, B)+1;
	while (r-l > 1) {
		ll md = (l+r)/2;
		ll ra = R-md;
		ll rb = B-md;
		if (md <= ra/(x-1) + rb/(y-1)) {
			l = md;
		} else {
			r = md;
		}
	}
	cout << l << endl;
	return 0;
}