#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <bitset>
#include <string>
#include <stack>
#include <cmath>
#include <set>
#include <map>
#include <list>
#include <deque>
using namespace std;
#define INF 100005
#define LLINF 100000000000000
typedef pair<int, int> P;
typedef long long ll;
#define pb push_back
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define VSORT(v) sort(v.begin(), v.end());
#define fi first
#define se second
#define out(x) cout << x << endl;
int dx[] = { 1, 0, -1, 0 }, dy[] = { 0,1,0,-1 };
ll MOD = 1000000007;
int q;
int f[100005] = { 0 };
int dp[INF] = { 0 };
int main() {
	f[2] = 0;
	for (int i = 2; i <= sqrt(INF); i++) {
		if (f[i] == 0) {
			for (int j = i + 1; j <= INF; j++) {
				if (j%i == 0) f[j] = 1;
			}
		}
	}
	f[1] = 1;
	for (int i = 3; i < INF; i+=2) {
		if (f[i] == 0 && f[(i + 1) / 2] == 0) dp[i] = 1;
		dp[i] += dp[i - 2];
	}
	cin >> q;
	rep(i, q) {
		int a, b, cnt = 0;
		cin >> a >> b;
		if (a != 1) {
			out(dp[b] - dp[a - 2]);
		}
		else out(dp[b]);
	}
	return 0;
}