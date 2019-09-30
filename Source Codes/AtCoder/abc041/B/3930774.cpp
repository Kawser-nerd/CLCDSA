#include <iostream>

using namespace std;

int main() {
	long long a, b, c;
	cin >> a >> b >> c;
	const int mod = 1000000007;
	cout << ((a*b) % mod*c) % mod << endl;
	return 0;
}