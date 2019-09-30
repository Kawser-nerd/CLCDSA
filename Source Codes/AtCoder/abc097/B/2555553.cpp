#include <iostream>

using namespace std;

int main() {
	int x;
	cin >> x;
	
	int maxp = 1;
	for (int i = 2; i * i <= x; i++) {
		int t = i * i;
		while (t <= x) {
			if (t > maxp) maxp = t;
			t *= i;
		}
	}

	cout << maxp << endl;

	return 0;
}