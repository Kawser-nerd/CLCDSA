#include <iostream>
using namespace std;
int main() {
	int A, B, C, X, Y;
	int x, y, sum;
	int min = 1000000000;
	cin >> A >> B >> C >> X >> Y;

	for (int i = ((X > Y) ? X : Y);i >= 0;i--) {
		sum = i * C * 2;
		x = X - i;
		y = Y - i;

		if (x > 0)
			sum += x * A;
		if (y > 0)
			sum += y * B;
		if (sum < min)
			min = sum;
	}

	cout << min << endl;

	return 0;
}