#include <iostream>

using namespace std;
int main() {
	long long x, y;

	cin >> x >> y;

    long long a = x;
	int count = 0;
	while (a <= y) {
		count++;
		a *= 2;
	}

	cout << count << endl;
	return 0;
}