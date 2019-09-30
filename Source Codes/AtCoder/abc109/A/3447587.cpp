#include <iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	int s = a * b;

	if (s % 2 != 0)
		cout << "Yes\n";
	else
		cout << "No\n";
}