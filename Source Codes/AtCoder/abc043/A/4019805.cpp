#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	unsigned long long a;
	cin >> a;
	cout << a * (a + 1) / 2 << endl;
	return 0;
}