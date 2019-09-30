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
		string s;
		cin >> s;
		ll n = sz(s), k;
		cin >> k;
		
		ll res = 0;
		FOR(i,0,n) if (i+k <= n && s[i] == '-') {
			res++;
			FOR(j,i,i+k) s[j] = (s[j] == '-') ? '+' : '-';
		}
		
		cout << "Case #" << tc << ": ";
		if (s == string(n,'+')) cout << res << endl;
		else cout << "IMPOSSIBLE" << endl;
	}

}

