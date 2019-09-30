#include <iostream>
using namespace std;

int main() {
	int a, b;
	
	cin >> a >> b;
	int ans = 0;

	if (a + b >= 24) ans = a + b - 24;
	else ans = a + b;

	cout << ans << endl;
}