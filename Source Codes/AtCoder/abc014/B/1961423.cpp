#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include<cstdio>
#include<functional>
#include <bitset>
using namespace std;

int main()
{
	int n, x, y, ans = 0;
	string z;
	
	cin >> n >> x ;
	bitset<20> b(x);

	for (int i = 0; i < n; i++) {
		cin >> y;

		if (b[i] == 1) {
			ans += y;
		}
	}

	cout << ans << endl;

	return 0;
}