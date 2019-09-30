#include <iostream>
#include <numeric>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <math.h>
#include <cmath>
#include <set>   
#include <boost/math/common_factor_rt.hpp>

#define ll long long

using namespace std;

int main() {
	int a[4];
	string s;
	cin >> s;
	for (int i = 0; i < 4; i++)
	{
		a[i] = s[i] - '0';
	}

	for (int x = 0; x < (1 << 4); x++)
	{
		int sum = a[0];
		string s;
		s += (char)('0' + a[0]);
		for (int i = 0; i < 3; i++)
		{
			if (x & (1 << i)) {
				sum += a[i + 1];
				s += '+';
				s += (char)('0' + a[i + 1]);
			}
			else {
				sum -= a[i + 1];
				s += '-';
				s += (char)('0' + a[i + 1]);
			}
		}

		if (sum == 7) {
			cout << s << "=7" << endl;
			return 0;
		}
	}

	
}

int dsum(ll a) {
	int ans = 0;
	while (a != 0) {
		ans += a % 10;
		a /= 10;
	}
	return ans;
}