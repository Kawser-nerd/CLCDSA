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
//#include <boost/math/common_factor_rt.hpp>

#define ll long long
int L = 1000000007;
using namespace std;
ll num[100050];

int main()
{
	ll n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		num[a] += b;
	}

	for (int i = 1; i <= 100000; ++i)
	{
		if (k <= num[i]) {
			cout << i << endl;
			return 0;
		}
		k -= num[i];
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