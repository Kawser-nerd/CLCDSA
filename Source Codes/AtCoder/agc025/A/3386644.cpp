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
	ll n;
	ll ans = 1000000;
	cin >> n;

	for (int i = 1; i < n; i++)
	{
		ll sum = 0;
		ll dig = 0;
		ll a = i;
		ll b = n - a;

		while (a) {
			dig = a % 10;
			sum = sum + dig;
			a = a / 10;
		}

		ll A = sum;

		sum = 0;
		dig = 0;

		while (b) {
			dig = b % 10;
			sum = sum + dig;
			b = b / 10;
		}

		ll B = sum;

		ans = min(ans, A + B);

	}

	cout << ans << endl;
}