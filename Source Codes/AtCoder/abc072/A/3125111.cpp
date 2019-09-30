#include <iostream>
using namespace std;
int main() {
	int X, t;
	int ans;

	cin >> X >> t;

	if (X - t <= 0)
		ans = 0;
	else
		ans = X - t;

	cout << ans << endl;

	return 0;
}