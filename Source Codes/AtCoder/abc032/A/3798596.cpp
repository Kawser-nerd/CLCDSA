#include <iostream>
using namespace std;

int main() {
	int a, b, n; cin >> a >> b >> n;
	while (!(n % a == 0 && n % b == 0)) {
		n++;
	}
	cout << n << endl;
}