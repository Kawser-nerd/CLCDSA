#include <iostream>

using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;

	if (a > b) swap(a, b);
	if (b > c) swap(b, c);
	if (a > b) swap(a, b);

	b -= a;
	c -= a;
	a = 0;

	int ans = 0;
	ans += b / 2;
	c -= 2 * (b / 2);
	b -= 2 * (b / 2);

	if (b == 0) {
		ans += c;
	} else {
		ans += c + 1;
	}
	cout << ans << endl;
	return 0;
}