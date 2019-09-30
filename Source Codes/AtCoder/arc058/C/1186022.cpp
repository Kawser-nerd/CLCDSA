#include <iostream>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

template<typename A, typename B> inline bool chmax(A &a, B b) { if (a<b) { a=b; return 1; } return 0; }
template<typename A, typename B> inline bool chmin(A &a, B b) { if (a>b) { a=b; return 1; } return 0; }

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, pii> P;

const ll INF = 1<<29;
const ll MOD = 1000000007;
const double EPS  = 1e-10;

int n, x[3];
ll dp[41][1<<17];
int p[1<<17];

ll mod_pow(ll x, ll n, ll mod) {
	if (n == 0) return 1;
	ll res = mod_pow(x * x % mod, n / 2, mod);
	if (n & 1) res = res * x % mod;
	return res;
}

int main() {
	cin >> n;
	REP(i, 3) cin >> x[i];
	int keta = x[0] + x[1] + x[2];
	
	REP(i, 17) p[1<<i] = i;
	
	dp[0][0] = 1;
	
	REP(i, n) {
		REP(j, 1 << keta) {
			if (!dp[i][j]) continue;
			
			FOR(k, 1, 11) {
				int num = j << k | 1 << (k - 1);
				num &= (1 << keta) - 1;
				
				int now = num;
				int pos = 2, sum = 0;
				
				while (now > 0) {
					int last = p[now & -now] + 1;
					
					sum += last;
					if (sum == x[pos]) pos--, sum = 0;
					
					now >>= last;
				}
				if (pos == -1) continue;
				
				(dp[i + 1][num] += dp[i][j]) %= MOD;
			}
		}
	}
	
	ll ans = 0;
	REP(i, 1 << keta) (ans += dp[n][i]) %= MOD;
	ans = (mod_pow(10, n, MOD) - ans + MOD) % MOD;
	
	cout << ans << endl;
	
	return 0;
}