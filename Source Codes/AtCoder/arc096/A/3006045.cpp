#include <iostream>
#include <algorithm>
using namespace std;
int a, b, c, x, y, m, ans = 0;
int main() {
	cin >> a >> b >> c >> x >> y;

	if (c * 2 <= a + b) {
		ans += 2 * (m = min(x, y))*c;
		x -= m;
		y -= m;
	}

	ans += x * min(2 * c, a);
	ans += y * min(2 * c, b);
	
	cout << ans << endl;

	return 0;
}