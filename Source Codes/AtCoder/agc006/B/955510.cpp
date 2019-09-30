#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, x;
	cin >> n >> x;

	if (x == 1) {
		cout << "No" << endl;
		return 0;
	}
	else if (x == 2 * n - 1) {
		cout << "No" << endl;
		return 0;
	}

	cout << "Yes" << endl;
	for (int i = 0; i < 2 * n - 1; i++) {
		cout << (i + x + n - 1) % (2 * n - 1) + 1 << endl;
	}
	return 0;
}