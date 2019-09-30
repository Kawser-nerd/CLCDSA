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
		ll n, k; cin >> n >> k;
		
		map<ll,ll> cnt;
		cnt[n] = 1;

		pll res;
		while (k > 0) {
			ll m, c;
			tie(m,c) = *cnt.rbegin();
			cnt.erase(m);
			
			ll m1 = m/2, m2 = (m-1)/2;
			res = {m1,m2};
			k -= c;
			cnt[m1] += c, cnt[m2] += c;
		}
		
		cout << "Case #" << tc << ": " << res.xx << " " << res.yy << endl; 
	}


}

