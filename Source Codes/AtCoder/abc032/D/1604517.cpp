#include<iostream>
#include<algorithm>
#include<functional>
#include <string>
#include<iomanip>
#include<cstdio>
#include<math.h>
#include<stack>
#include<queue>
#include<cstring>
#include<vector>
typedef long long int ll;
#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define EREP(i,n) for(int i=(n-1);i>=0;--i)
#define D(n,retu) REP(i,n){cin>>retu[i];}
#define mod 1000000007
#define MIN -93193111451418101
#define INF 931931114518101
using namespace std;
typedef pair<ll, ll>P;
template<typename T>
void fill_all(T& arr, const T& v) {
	arr = v;
}
template<typename T, typename ARR>
void fill_all(ARR& arr, const T& v) {
	for (auto& i : arr) { fill_all(i, v); }
}
#define MAX_NUM 50
long long comb[MAX_NUM + 1][MAX_NUM + 1];

ll par[100000], depth[100000];
static void calc_comb()
{
	for (uint32_t i = 0; i <= MAX_NUM; i++) {
		for (uint32_t j = 0; j <= i; j++) {
			if ((j == 0) || (i == j)) {
				comb[i][j] = 1;
			}
			else {
				comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
			}
		}
	}
}
#define yo 100001
//------------------??-----------------------//

//-------------------??----------------------//


		ll dp[203][200105] = {};//omosa?????
int main() {
	ll n, weight, v[100001], w[100001];
	P p[100000];
	cin >> n >> weight;
	REP(i, n) { cin >> v[i] >> w[i]; }
	if (n <= 30) {
		ll n2 = n / 2;//??B
		REP(i, 1 << n2) {
			ll vv = 0, ww = 0;
			REP(j, n2) {
				if ((i >> j) & 1) {
					vv += v[j];
					ww += w[j];
				}
				p[i] = P(ww, vv);
			}
		}
		sort(p, p + (1 << n2));
		ll m = 1;
		REP(i, 1 << n2) {
			if (p[m - 1].second < p[i].second) { p[m++] = p[i]; }
		}
		ll res = 0;
		REP(i, 1 << (n - n2)) {
			ll ww = 0, vv = 0;
			REP(j, n - n2) {
				if ((i >> j) & 1) {
					ww += w[j + n2];
					vv += v[j + n2];
				}
			}
			if (ww <= weight) {
				ll cnt = (lower_bound(p, p + m, P(weight - ww, 1ll << 55)) - 1)->second;
				res = max(res, vv + cnt);
			}
		}
		cout << res << endl;
	}
	else if (*max_element(v, v + n) <= 1000) {
		REP(i, 201) { REP(j, 200001) { dp[i][j] = INF; } }
		dp[0][0] = 0;
		REP(i, n) {
			REP(j, 200010) {
				if (dp[i][j] + w[i] <= weight) { dp[i + 1][j + v[i]] = min(dp[i][j + v[i]], dp[i][j] + w[i]); }
				dp[i + 1][j] = min(dp[i+1][j],dp[i][j]);
			}
		}
		ll cnt = 0;
		REP(i, 200001) {
			if (dp[n][i] <= weight) { cnt = i; }
		}
		cout << cnt << endl;
	}
	else {
		REP(i, n) {
			REP(j, 200010) {
				if (j + w[i] <= weight) {
					dp[i + 1][j + w[i]] = max(dp[i][j + w[i]], dp[i][j] + v[i]);
				}
					dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
			}
		}
		for (ll i = weight; i >= 0; i--) {
			if (dp[n][i] != 0) {
				cout << dp[n][i] << endl;
				break;
			}
		}
	}
	return 0;
}