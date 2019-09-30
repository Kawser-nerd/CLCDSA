#include<iostream>

using namespace std;

int main() {
	int a, b, c;

	cin >> a >> b >> c;
	if (a > b) {
		if (a > c) {
			cout << b + c;
		}
		else {
			cout << b + a;
		}
	}
	else {
		if (b > c) {
			cout << a + c;
		}
		else {
			cout << a + b;
		}
	}
	return 0;

}