#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <limits>
using namespace std;

int dp[1000001];

unsigned long long int f(unsigned long long int n) {
	if (dp[n] == numeric_limits<int>::max() / 2) {
		if (n == 1) {
			return 0;
		}
		else if (n == 2) {
			return 0;
		}
		else if (n == 3) {
			return 1;
		}
		else {
			 dp[n] = (f(n - 1) + f(n - 2) + f(n - 3)) % 10007;
			 return dp[n];
		}
	}
	else {
		return dp[n];
	}
}

int main() {	
	unsigned long long int n;

	cin >> n;

	for (int i = 0; i < 1000001; i++) {
		dp[i] = numeric_limits<int>::max() / 2;
	}

	n = f(n);

	cout << n << endl;
}