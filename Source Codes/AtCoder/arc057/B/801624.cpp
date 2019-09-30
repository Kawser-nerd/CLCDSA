#include <iostream>
#include <queue>
#include <map>
#include <list>
#include <vector>
#include <string>
#include <limits>
#include <cassert>
#include <fstream>
#include <cstring>
#include <bitset>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <ciso646>
#include <array>

using namespace std;

#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)

#define inf 0x3f3f3f3f
#define uinf 0x3f3f3f3f3f3f3f3f
#define CLEAR(a) a = decltype(a)()
#define MP make_pair
#define ALL(a) (a).begin(),(a).end()
#define pii pair<int ,int>
#define pcc pair<char,char>
#define pic pair<int,char>
#define pci pair<char,int>
#define VS vector<string>
#define VI vector<int>
#define VVI vector<vector<int>>
#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define pi 2*acos(0.0)
#define INFILE() freopen("in.txt","r",stdin)
#define OUTFILE() freopen("out.txt","w",stdout)
#define ll long long
#define ull unsigned long long
#define eps 1e-14
#define FIN std::ifstream cin("D:\input.txt")

#define int ull

int dp[2000][2001] = {};

signed main() {
	int N, K; cin >> N >> K;
	vector<int> A(N), psum(N);
	REP(i, N) REP(j, N + 1) dp[i][j] = uinf;
	for (auto &a : A) cin >> a;
	psum[0] = A[0];
	FOR(i, 1, N) {
		psum[i] = psum[i - 1] + A[i];
	}
	if (K == 0) {
		cout << 0 << endl;
		return 0;
	}
	if (psum[N-1] == K) {
		cout << 1 << endl;
		return 0;
	}

	dp[0][0] = 0;
	dp[0][1] = 1;
	FOR(i, 1, N) {
		dp[i-1][0] = 0;
		FOR(j, 1, N+1) {
			int nxt = dp[i - 1][j - 1] * A[i] / psum[i - 1] + 1;
			if (nxt > uinf) nxt = uinf;
			dp[i][j] = min(dp[i-1][j-1] + nxt, dp[i - 1][j]);
		}
	}
	dp[N - 1][0] = 0;

	int res = uinf;
	REP(i, N+1) {
		if (dp[N - 1][i] <= K) res = i;
	}
	cout << res << endl;
	return 0;
}