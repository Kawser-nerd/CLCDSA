#include <iostream>
using namespace std;
/*
??????
???????
inline long long R(long long n) {
	if (n == 0) {
		return 2;
	}
	else if (n == 1) {
		return 1;
	}
	else {
		return R(n - 1) + R(n - 2);
	}
}
*/

int main() {
	int n;
	long long a[87];

	cin >> n;

	a[0] = 2;
	a[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		a[i] = a[i - 1] + a[i - 2];
	}

	cout << a[n] << endl;

	return 0;
}