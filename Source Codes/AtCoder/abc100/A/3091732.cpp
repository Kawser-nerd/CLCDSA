#include <iostream>
using namespace std;
int main() {
	int A, B;

	cin >> A >> B;
	if (A + B > 16) {
		cout << ":(" << endl;
	}
	else {
		if (A > 8 || B > 8) {
			cout << ":(" << endl;
		}
		else {
			cout << "Yay!" << endl;
		}
	}

	return 0;
}