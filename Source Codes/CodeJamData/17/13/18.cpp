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
		array<ll,4> st0;
		FOR(i,0,4) cin >> st0[i];
		
		ll H = st0[0], b, d;
		cin >> b >> d;

		map<array<ll,4>,ll> dist;
		queue<array<ll,4>> q;
		
		ll res = oo;
		q.push(st0);
		dist[st0] = 0;
		while (sz(q)) {
			auto st = q.front();
			q.pop();
			
			ll h1 = st[0], a1 = st[1], h2 = st[2], a2 = st[3];

			if (a1 >= h2) {
				res = dist[st]+1;
				break;
			}
			
			vector<array<ll,4>> v;

			v.pb({h1,a1,h2-a1,a2});
			v.pb({h1,a1+b,h2,a2});
			v.pb({H,a1,h2,a2});
			v.pb({h1,a1,h2,max(0LL,a2-d)});
			
			for (auto &st1: v) {
				st1[0] -= st1[3];
				if (st1[0] <= 0) continue;
				if (has(dist,st1)) continue;
				dist[st1] = dist[st]+1;
				q.push(st1);
			}
		}
		cout << "Case #" << tc << ": ";
		if (res < oo) cout << res << endl;
		else cout << "IMPOSSIBLE" << endl;
	}


}

