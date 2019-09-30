#include <iostream>
using namespace std;
int main() {
	int A, B, X;

	cin >> X >> A >> B;

	X -= A;
	X %= B;

	cout << X << endl;

	return 0;
}