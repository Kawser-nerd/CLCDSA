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

vector<int> dp;
vector<int> cost;

int main(void) {
	int N, K; cin >> N >> K;
	VVI W(N);
	REP(i, N) {
		W[i].resize(N);
		for (auto &a : W[i]) {
			cin >> a;
		}
	}
	dp.resize(1 << N);
	cost.resize(1 << N);

	FOR(S, 1, 1 << N) {
		REP(i, N) {
			if (not ((S >> i) & 1)) continue;
			REP(j, i) {
				if (not ((S >> j) & 1)) continue;
				cost[S] += W[i][j];
			}
		}
	}

	FOR(S, 1, 1 << N) {
		int mask = S;
		while(mask){
			dp[S] = max(dp[S], K + dp[S - mask] - (cost[S] - cost[mask] - cost[S-mask]));
			mask = (mask - 1) & S;
		}
	}

	cout << dp[(1 << N) - 1] << endl;
	return 0;
}