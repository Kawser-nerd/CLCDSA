#include <iostream>
using namespace std;
inline int sum(int a, int b) {
	int sum = 0;

	for (int i = a; i <= b; i++)
	{
		sum += i;
	}

	return sum;
}

int main() {
	int a, b;
	cin >> a >> b;

	cout << sum(1, (b - a - 1)) - a << endl;

	return 0;
}