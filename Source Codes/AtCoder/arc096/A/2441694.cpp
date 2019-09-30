#include <iostream>

using namespace std;

int main() {
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;

	int c2 = 2 * c;
	if (a + b < c2) c2 = a + b;
	if (a > c2) a = c2;
	if (b > c2) b = c2;

	int cc = min(x, y);

	cout << cc * c2 + (x - cc) * a + (y - cc) * b << endl;
	return 0;
}