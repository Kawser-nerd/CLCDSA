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
int dp[100001];
int input[100001];


int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		input[i] = tmp;
	}

	dp[0] = 0;
	dp[1] = abs(input[1] - input[0]);

	for (int i = 2; i < N; i++) {
		dp[i] = min(dp[i - 1] + abs(input[i] - input[i - 1]), dp[i - 2] + abs(input[i] - input[i - 2]));
	}
	cout << dp[N - 1] << "\n";
}