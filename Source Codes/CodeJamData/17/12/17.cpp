#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pll;
typedef vector<bool> vb;
const ll oo = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9;
#define sz(c) ll((c).size())
#define all(c) begin(c), end(c)
#define FOR(i,a,b) for (ll i = (a); i < (b); i++)
#define FORD(i,a,b) for (ll i = (b)-1; i >= (a); i--)
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define has(c,i) ((c).find(i) != end(c))
#define DBGDO(X) ({ if(1) cerr << "DBGDO: " << (#X) << " = " << (X) << endl; })

int main() {
	ll TC; cin >> TC;
	FOR(tc,1,TC+1) {
		ll n, p;
		cin >> n >> p;
		
		vl need(n);
		FOR(i,0,n) cin >> need[i];

		vvl pack(n,vl(p));
		FOR(i,0,n) FOR(j,0,p) cin >> pack[i][j];
		FOR(i,0,n) sort(all(pack[i]));

		vl ind(n);

		ll res = 0;
		FOR(k,0,1e6+10) {
			while (true) {
				bool can = true;
				FOR(i,0,n) {
					while (ind[i] < p && 10*pack[i][ind[i]] < 9*k*need[i]) ind[i]++;
					can = can && (ind[i] < p && 10*pack[i][ind[i]] <= 11*k*need[i]);
				}
				if (can) {
					res++;
					FOR(i,0,n) ind[i]++;
				} else break;
			}
		}		
		cout << "Case #" << tc << ": " << res << endl;
	}


}

