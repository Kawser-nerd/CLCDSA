#include<iostream>
#include <limits.h>

#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
#pragma GCC optimize ("-O3")
using namespace std; void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }
//---------------------------------------------------------------------------------------------------
/*---------------------------------------------------------------------------------------------------
??????????? ???
			????? ??? ??´<_? ?? Welcome to My Coding Space!
				  ???? ? ´_?`??/? ?i
					   ?????????? ?  |?|
						   ??? /?? /????/??|
							   ? ?_(__??/?    ?/ .| .|????
								 ? ????/????/??u??
									  ---------------------------------------------------------------------------------------------------*/






int N, M; ll X[1010], Y[1010], Z[1010];
ll dp[1010][1010];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> M;
	rep(i, 0, N) cin >> X[i] >> Y[i] >> Z[i];

	ll ans = -infl;
	rep(a, -1, 2) rep(b, -1, 2) rep(c, -1, 2) if (a) if (b) if (c) {
		rep(i, 0, N + 1) rep(j, 0, M + 1) dp[i][j] = -infl;
		dp[0][0] = 0;
		rep(i, 0, N) rep(j, 0, M + 1) {
			ll d = a * X[i] + b * Y[i] + c * Z[i];
			chmax(dp[i + 1][j], dp[i][j]);
			chmax(dp[i + 1][j + 1], dp[i][j] + d);
		}
		chmax(ans, dp[N][M]);
	}
	cout << ans << endl;

	getchar(); getchar();
}