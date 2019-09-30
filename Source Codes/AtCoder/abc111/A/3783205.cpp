#include<iostream>
using namespace std;

int main() {

	char a[3];
	int i;

	for (i = 0; i < 3; i++) {
		cin >> a[i];
	}

	for (i = 0; i < 3; i++) {
		if (a[i] == '1') {
			a[i] = '9';
		}
		else if (a[i] == '9') {
			a[i] = '1';
		}
		cout << a[i];
	}

	return 0;
}