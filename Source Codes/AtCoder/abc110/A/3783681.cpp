#include<iostream>
using namespace std;

int main() {

	int x[3],i,j,k;

	for (i = 0; i < 3; i++) {
		cin >> x[i];
	}

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 2; j++) {
			if (x[j] < x[j + 1]) {
				k = x[j];
				x[j] = x[j + 1];
				x[j + 1] = k;
			}
		}
	}

	cout << x[0] * 10 + x[1] + x[2];

	return 0;
}