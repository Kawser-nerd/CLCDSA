#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include <deque>
#include <string>
#include <stack>
#include <unordered_set>
#include <cmath>
#include <climits>
#include <cstdlib>
#define endl '\n'
#define ll long long
#define mod 1000000007
#define NCONS 201
#define PLUS 0
#define MINUS 1

using namespace std;

ll *dp;

ll LucasNumber(int i)
{
	if (dp[i] != 0)
		return dp[i];
	dp[i] = LucasNumber(i - 1) + LucasNumber(i - 2);
	return dp[i];
}

int main(void)
{
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	dp = new ll[N + 1]();
	dp[0] = 2; dp[1] = 1;


	cout << LucasNumber(N) << endl;
	return 0;
}