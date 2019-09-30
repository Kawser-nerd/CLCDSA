#include<iostream>
using namespace std;

int main() {

	int a, b, i;

	cin >> a >> b;
	for (i = 1; i < 4; i++) {
		if ((a*b*i) % 2 == 1) {
			cout << "Yes";
			break;
		}
		else {
			cout << "No";
			break;
		}
	}

	return 0;
}