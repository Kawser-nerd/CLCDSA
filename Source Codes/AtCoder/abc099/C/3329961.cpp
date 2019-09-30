#include <iostream>
#include <numeric>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <math.h>
#include <cmath>
#include <deque>
#include <limits>
#include <numeric>
#include <boost/math/common_factor_rt.hpp>


#define INF 100000000
#define MOD 1000000007

#define ll long long

using namespace std;
int dp[100050];

int main() {
	dp[0] = 0;
	for (int i = 1; i < 100010; i++)
	{
		dp[i] = INF;
		int power = 1;
		while (power <= i) {
			dp[i] = min(dp[i], dp[i - power] + 1);
			power *= 6;
		}

		power = 1;
		while (power <= i) {
			dp[i] = min(dp[i], dp[i - power] + 1);
			power *= 9;
		}

	}
	int n;
	cin >> n;
	cout << dp[n] << endl;
	return 0;
}