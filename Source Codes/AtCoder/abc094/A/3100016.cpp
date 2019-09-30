#include <iostream>
using namespace std;
int	main() {
	int A, B, X;
	cin >> A >> B >> X;

	if (B >= (X - A)&&(A<=X)) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}

	return 0;
}