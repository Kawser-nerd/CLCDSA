// .... .... .....!
// ...... ......!
// .... ....... ..... ..!

#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define fer(i, x, n) for (int i = (int)(x), _n = (int)(n); i < _n; i++)
#define rof(i, n, x) for (int i = (int)(n), _x = (int)(x); i-- > _x; )
#define sz(x) (int((x).size()))
#define pb push_back
#define all(X) (X).begin(),(X).end()
#define X first
#define Y second

template<class P, class Q> inline void smin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void smax(P &a, Q b) { if (a < b) a = b; }

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const long double eps = 1e-18;
const long double inf = 1e18;
const int maxn = 100 + 10;

int n;
ll v, t;
pair<ll, ll> p[maxn];

long double calc(long double tm, int dir) {
	long long rem = v;
	long double cur = 0;
	long double temp = 0;
	for(int i = (dir == 0 ? 0 : n-1); 0 <= i && i < n; i += (dir == 0 ? 1 : -1)) {
		long double add = min(rem, p[i].Y * tm);
		rem -= add;
		temp = (cur * temp + add * p[i].X) / (cur + add);
		cur += add;
	}
	return temp;
}

void solve() {
	double vol, temp;
	cin >> n >> vol >> temp;
	t = int(temp * 10000 + 0.5);
	v = int(vol  * 10000 + 0.5);
	rep(i, n) {
		cin >> vol >> temp;
		p[i].X = int(temp * 10000 + 0.5);
		p[i].Y = int(vol  * 10000 + 0.5);
	}

//	rep(i, n) p[i].Y /= v;
//	v = 1;

	sort(p, p+n);

	if(t < p[0].X || t > p[n-1].X) { cout << "IMPOSSIBLE" << endl; return; }

	ll tot = 0;
	rep(i, n) tot += p[i].Y;

	long double lo = v / (long double)tot, hi = 1e9;
	rep(z, 300) {
		long double md = (lo + hi) / 2;
		
		long double mn = calc(md, 0);
		long double mx = calc(md, 1);

		if(mn <= t+eps && t-eps <= mx)
			hi = md;
		else
			lo = md;
	}

	cout.setf(ios::fixed);
	cout.precision(9);
	if(hi > inf / 2) cout << "IMPOSSIBLE" << endl;
	else cout << hi << endl;

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int ttt; cin >> ttt;
	fer(ttc, 1, ttt+1) {
		cout << "Case #" << ttc << ": ";
		solve();
	}

	return 0;
}

