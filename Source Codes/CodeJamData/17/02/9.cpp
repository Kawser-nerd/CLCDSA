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

set<ll> tidies;

void rec(ll i, ll d, ll x) {
	if (i == 18) {
		tidies.insert(x);
		return;
	}
	for (; d < 10; d++) {
		rec(i+1, d, 10*x+d);
	}
}

int main() {
	rec(0,0,0);
//	cerr << tidies.size();
//	cerr << *tidies.rbegin() << endl;
	
	ll TC; cin >> TC;
	FOR(tc,1,TC+1) {
		ll n; cin >> n;
		cout << "Case #" << tc << ": ";
		auto it = tidies.upper_bound(n);
		it--;
		cout << *it << endl;
	}


}

