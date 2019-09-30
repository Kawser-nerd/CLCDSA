#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	int res = 3;

	cin >> a >> b >> c;

	if (a == b | a == c | b == c) {
		if (a == b && b == c) res = 1;
		else res = 2;
	}
	cout << res << endl;
}