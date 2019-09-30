#include <iostream>

using namespace std;

int main() {
	long long  n;
	cin >> n;
	long long power = 1;
	for(long long i = 1; i <= n; i++) {
		power *= i;
		power = power % (1000000000 + 7);
	}
	cout << power << endl;
	return 0;
}