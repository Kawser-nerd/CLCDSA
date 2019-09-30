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
#include <cstring>
#include <map>
#define endl '\n'
#define ll long long
#define mod 1000000007
#define NCONS 90001

using namespace std;

int H, W, D, Q, L, R;
int lx[NCONS], ly[NCONS];
int dp[NCONS];

int main(void)
{
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> H >> W >> D;
	for (int i = 1; i <= H; i++)
	{
		for (int j = 1; j <= W; j++)
		{
			int a; cin >> a;
			lx[a] = i;
			ly[a] = j;
		}
	}

	for (int i = D + 1; i <= H * W; i++)
	{
//		cout << i - D << " " << abs(lx[i] - lx[i - D]) << " " << abs(ly[L] - ly[L - D]) << endl;
		dp[i] = dp[i - D] + abs(lx[i] - lx[i - D]) + abs(ly[i] - ly[i - D]);
	}


	cin >> Q;

	while (Q--)
	{
		cin >> L >> R;
		cout << dp[R] - dp[L] << endl;
	}

	return 0;
}