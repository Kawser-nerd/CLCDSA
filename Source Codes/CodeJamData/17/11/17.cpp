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
		ll m, n; cin >> m >> n;

		vector<string> a(m);
		FOR(i,0,m) {
			cin >> a[i];
			FOR(j,1,n) if (a[i][j] == '?') a[i][j] = a[i][j-1];
			FORD(j,0,n-1) if (a[i][j] == '?') a[i][j] = a[i][j+1];
		}
		
		FOR(i,1,m) if (a[i] == string(n,'?')) a[i] = a[i-1];
		FORD(i,0,m-1) if (a[i] == string(n,'?')) a[i] = a[i+1];

		cout << "Case #" << tc << ":" << endl;
		FOR(i,0,m) cout << a[i] << endl;
	}


}

