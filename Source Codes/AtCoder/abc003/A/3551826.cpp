#include <iostream>
using namespace std;

#define rep(i, n) for(int i = 0;i <= n; i++)

int main() {
	int x;
	cin >> x;
	int sum = 0;

	rep(i, x) sum += 10000 * i;
	cout << sum / x << endl;
//	system("pause");
	return 0;
}