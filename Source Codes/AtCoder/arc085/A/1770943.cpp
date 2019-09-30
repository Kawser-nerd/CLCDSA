#include <iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	cout << (1900 * m + 100 * (n - m)) * (1 << m) << endl;
	return 0;
}