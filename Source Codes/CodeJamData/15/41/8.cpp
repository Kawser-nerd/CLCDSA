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

const string dirs = "^>v<";
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};


int n, m;
string s[111];

inline bool in(int x, int y) {
	return 0 <= x && 0 <= y && x < n && y < m;
}

bool good(int x, int y, int dir) {
	for(x += dx[dir], y += dy[dir]; in(x, y); x += dx[dir], y += dy[dir])
		if(s[x][y] != '.')
			return true;
	return false;
}

void solve() {
	cin >> n >> m;
	rep(i, n) cin >> s[i];

	int ans = 0;
	rep(i, n) rep(j, m) if(s[i][j] != '.') {
		int dir = dirs.find(s[i][j]);
		if(good(i, j, dir)) continue;
		ans++;
		bool ok = false;
		rep(d, 4) if(good(i, j, (dir + d) % 4)) ok = true;

		if(!ok) {
			cout << "IMPOSSIBLE" << endl;
			return;
		}
	}
	cout << ans << endl;
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

