#include <cstdio>
#include <vector>
#include <stack>
#include <iostream>
#include <string>
#include <tuple>
#include <random>
#include <map>
#include <queue>
#include <set>
#include <complex>
#include <algorithm>
#include <cassert>
#include <iterator>
#include <numeric>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<ll, ll> P;

const ll INF = 1e15;
const double eps = 1e-6;
const ll MOD = 1000000007;

vector<vector<vector<int>>> dp;


bool memo(int a, int b, int k) {
	if (k < 0)
		return false;
	if (dp[a][b][k] != -1)
		return dp[a][b][k];
	if (a == b)
		return dp[a][b][k] = true;
	if (b >= (a + 1) / 2)
		return dp[a][b][k] = false;
	if (k == 0)
		return dp[a][b][k] = false;
	bool ret = false;
	ret |= memo(a % k, b, k - 1);
	ret |= memo(a, b, k - 1);
	return dp[a][b][k] = ret;
}

int main() {
	dp = vector<vector<vector<int>>>(51, vector<vector<int>>(51, vector<int>(51, -1)));
	ll N;
	cin >> N;
	vector<ll> a(N);
	for (int i = 0;i < N;i++)
		cin >> a[i];
	vector<ll> b(N);
	for (int i = 0;i < N;i++)
		cin >> b[i];
	bool exist = true;
	for (int i = 0;i < N;i++) {
		if (b[i] >= (a[i] + 1) / 2 && a[i] != b[i])
			exist = false;
	}
	if (!exist) {
		cout << -1 << endl;
		return 0;
	}

	vector<ll> ans;
	ll answer = 0;
	vector<vector<int>> from(N, vector<int>(51, false));
	for (int i = 0;i < N;i++)
		from[i][a[i]] = true;
	for (ll check = 50;check >= 1;check--) {
		bool ok = true;
		for (int i = 0;i < N;i++) {
			bool nowok = false;
			for (int j = 0;j <= 50;j++)
				if (from[i][j])
					nowok |= memo(j, b[i], check - 1);
			ok &= nowok;
		}
		if (!ok) {
			ans.push_back(check);
			answer += 1LL << check;
			for (int i = 0;i < N;i++)
				for (int j = 50;j >= 0; j--)
					from[i][j % check] |= from[i][j];
		}
	}
	cout << answer << endl;
	return 0;
}