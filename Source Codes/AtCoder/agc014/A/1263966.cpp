#include <vector>
#include <deque>
#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <functional>
#include <numeric>

static const int INF = 1001001001;

using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	// 3??????????
	if (a%2!=0 || b%2!=0 || c%2!=0) {
		cout << 0 << endl;
		return 0;
	}
	// 3???4???????
	if (a%4!=0 && b%4!=0 && c%4!=0) {
		cout << -1 << endl;
		return 0;
	}
	// 3??????
	if (a==b && b==c && c==a) {
		cout << -1 << endl;
		return 0;
	}
	// ???????
	int count = 0;
	while (true) {
		count += 1;
		int a_2 = a/2;
		int b_2 = b/2;
		int c_2 = c/2;
		a = b_2 + c_2;
		b = a_2 + c_2;
		c = a_2 + b_2;
		if (a%2!=0 || b%2!=0 || c%2!=0) {
			cout << count << endl;
			break;
		}
	}
	return 0;
}