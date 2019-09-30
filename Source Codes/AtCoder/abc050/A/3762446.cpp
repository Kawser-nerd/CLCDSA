#include <iostream>
using namespace std;

int main() {
	int a, b;
	char op;
	int res = 0;

	cin >> a >> op >> b;

	if (op == '+') res = a + b;
	else res = a - b;

	cout << res << endl;
}