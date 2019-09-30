#include <iostream>
using namespace std;
int max(int a, int b) {
	return (a > b) ? a : b;
}

int main() {
	int A, B, C, D, E;

	cin >> A >> B;

	C = A + B;
	D = A - B;
	E = A * B;

	cout << max(C, max(D, E)) << endl;

	return 0;
}