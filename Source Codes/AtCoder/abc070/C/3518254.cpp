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
#include <bitset>
#include <boost/math/common_factor_rt.hpp>

#define ll long long
using namespace std;
ll t[105] = {};
int main()
{
	ll n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> t[i];
	}
	ll ans = t[0];

	for (int i = 1; i < n; i++)
	{
		ans = boost::math::lcm(ans, t[i]);
	}

	cout << ans << endl;
}

int dsum(ll a) {
	int ans = 0;
	while (a != 0) {
		ans += a % 10;
		a /= 10;
	}
	return ans;
}