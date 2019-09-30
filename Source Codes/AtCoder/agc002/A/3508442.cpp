#include <iostream>
#include <string>
using namespace std;

int main() {
	int64_t a, b;
	cin >> a >> b;
	string k;
	if (a * b <= 0)cout << "Zero" << endl;
	else if (a > 0 && b > 0) cout << "Positive" << endl;
	else if (a < 0 && b < 0) {
		int k = b - a + 1;
		if (k % 2 == 1) {
			cout << "Negative" << endl;
		}
		else {
			cout << "Positive" << endl;
		}
	}

	return 0;
}