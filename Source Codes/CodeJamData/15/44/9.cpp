// .... .... .....!
// ...... ......!
// .... ....... ..... ..!

#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define fer(i, x, n) for (int i = (int)(x), _n = (int)(n); i < _n; i++)
#define rof(i, n, x) for (int i = (int)(n), _x = (int)(x); i-- > _x; )
#define sz(x) (int((x).size()))
#define pb push_back
#define all(X) (X).begin(),(X).end()
#define X first
#define Y second

template<class P, class Q> inline void smin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void smax(P &a, Q b) { if (a < b) a = b; }

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int mod = 1000000000+7;

const int len[4] =  {1, 2, 2, 3};
const int loop[5] = {1, 3, 6, 4};
int dp[111][12+1];

int pm(int a, int p) {
	int r = 1;
	while(p) {
		if(p & 1) r = r * (ll)a % mod;
		a = a * (ll)a % mod;
		p /= 2;
	}
	return r;
}

inline void addto(int &x, ll y) {
	x = (x + y) % mod;
}

int solve() {
	int r, c;
	cin >> r >> c;

	memset(dp, 0, sizeof dp);
	dp[0][1] = 1;
	dp[1][1] = 1;
	if(c % 3 == 0) dp[2][3] = 3;
	if(c % 6 == 0) dp[2][6] = 6;
	if(c % 4 == 0) dp[3][4] = 4;

	fer(i, 3, r+1) {
		rep(t, 4) if(c % loop[t] == 0 && i - len[t] - 2 >= 0) {
			int j = i - len[t] - 2;
			fer(og, 1, 13) if(c % og == 0)
				addto(dp[i][og / __gcd(og, loop[t]) * loop[t]], dp[j][og] * (ll)loop[t]);
		}
	}
	fer(og, 1, 13)
		addto(dp[r][og], dp[r-2][og]);

	int ans = 0;
	fer(g, 1, 13) if(c % g == 0)
		addto(ans, dp[r][g] * (ll)pm(g, mod-2));

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int ttt; cin >> ttt;
	fer(ttc, 1, ttt+1) {
		cout << "Case #" << ttc << ": " << solve() << endl;
	}

	return 0;
}

