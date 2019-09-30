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

struct bipartite {
	ll L, R;
	vvl adj;
	vl pred;
	vb mark;
	
	bool find_match(ll i) {
		if (i == -1) return true;
		for (const ll &j: adj[i]) {
			if (mark[j]) continue;
			mark[j] = true;
			if (find_match(pred[j])) {
				pred[j] = i;
				return true;
			}
		}
		return false;
	}

	ll max_matching() {
		pred.assign(R,-1);
		ll res = 0;
		FOR(i,0,L) {
			mark.assign(R,false);
			if (find_match(i)) res++;
		}
		return res;
	}

	bipartite(ll L, ll R): L(L), R(R) {
		adj.resize(L);
	}
};

int main() {
	ll TC; cin >> TC;
	FOR(tc,1,TC+1) {
		ll n, m; cin >> n >> m;
		
		vb blockX(n), blockY(n), blockS(2*n), blockD(2*n);
		
		vector<string> grid(n,string(n,'.'));
		ll res = m;
		FOR(i,0,m) {
			char c;
			ll x, y;
			cin >> c >> x >> y;
			x--, y--;
			grid[x][y] = c;
			
			if (c == 'o') res++;

			if (c != '+') {
				blockX[x] = true;
				blockY[y] = true;
			}
			if (c != 'x') {
				blockS[x+y] = true;
				blockD[x-y+n] = true;
			}
		}
		
		bipartite orth(n,n), diag(2*n,2*n);
		
		FOR(x,0,n) FOR(y,0,n) {
			if (!blockX[x] && !blockY[y]) {
				orth.adj[x].pb(y);
			}
			ll s = x+y, d = x-y+n;
			if (!blockS[s] && !blockD[d]) {
				diag.adj[s].pb(d);
			}
		}
		
		res += orth.max_matching() + diag.max_matching();
		
		vector<string> ngrid = grid;
		
		FOR(y,0,n) if (orth.pred[y] != -1) {
			ll x = orth.pred[y];
			switch (ngrid[x][y]) {
			case '.': ngrid[x][y] = 'x'; break;
			case '+': ngrid[x][y] = 'o'; break;
			default: assert(0);
			}
		}
		FOR(d,0,2*n) if (diag.pred[d] != -1) {
			ll s = diag.pred[d];
			ll x = (s+d-n)/2, y = s-x;
			switch (ngrid[x][y]) {
			case '.': ngrid[x][y] = '+'; break;
			case 'x': ngrid[x][y] = 'o'; break;
			default: assert(0);
			}
		}

		ll cnt = 0;
		FOR(x,0,n) FOR(y,0,n) if (ngrid[x][y] != grid[x][y]) cnt++;
		cout << "Case #" << tc << ": " << res << " " << cnt << endl;
		FOR(x,0,n) FOR(y,0,n) if (ngrid[x][y] != grid[x][y]) {
			cout << ngrid[x][y] << " " << x+1 << " " << y+1 << endl;
		}
		

	}


}

