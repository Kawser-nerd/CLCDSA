#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define fill(x,y) memset(x,y,sizeof(x))
#define prev PREV
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }
template<class T> T sqr(T x) { re x * x; }
template<class T> T gcd(T a, T b) { re a ? gcd (b % a, a) : b; }

int n;
int m;

string s;
ll L, R;
vi v[100];
int w[100][10];
ll eps[100];
int p[100];
int q[100];
int was[100];
ii aut;
int r;
unordered_map<ll, ll> res[20][2][2];

int get () {
	v[m].clear ();
	eps[m] = 0;
	for (int i = 0; i < 10; i++) w[m][i] = -1;
	m++;
	re m - 1;
}

ii build (int l, int r) {
	if (s[l] == '(') {
		int k = p[l];
		int x = get ();
		int y = get ();
		if (k < r && s[k + 1] == '*') {
			ii a = build (l + 1, k - 1);
			v[a.se].pb (a.fi);
			v[x].pb (y);
			v[x].pb (a.fi);
			v[a.se].pb (y);
			k++;
		} else {
			int bal = 0, last = l;
			for (int i = l; i <= k; i++) {
				if (s[i] == '(') bal++; else
				if (s[i] == ')') bal--;
				if (bal <= 1 && (s[i] == '|' || i == k)) {
					ii a = build (last + 1, i - 1);
					v[x].pb (a.fi);
					v[a.se].pb (y);
					last = i;
				}
			}
		}
		if (k < r) {
			ii a = build (k + 1, r);
			v[y].pb (a.fi);
			re mp (x, a.se);
		} else re mp (x, y);
	}
	int x = get ();
	assert (s[l] >= '0' && s[l] <= '9');
	if (l == r) {
		int y = get ();
		w[x][s[l] - '0'] = y;
		re mp (x, y);
	} else {
		ii a = build (l + 1, r);
		w[x][s[l] - '0'] = a.fi;
		re mp (x, a.se);
	}	
}

int trace (int x) {
	int r = 0;
	while (x) {
		q[r++] = x % 10;
		x /= 10;
	}
	ll now = eps[aut.fi];
	for (int i = r - 1; i >= 0; i--) {
		ll cur = 0;
		for (int j = 0; j < m; j++)
			if (((now >> j) & 1) && w[j][q[i]] != -1)
				cur |= eps[w[j][q[i]]];
	   	now = cur;
	}
	re (now >> aut.se) & 1;
}

ll go (int n, int zero, int f, ll mask) {
	if (!mask) re 0;
	if (n == 0) re ((mask >> aut.se) & 1);
	if (res[n][zero][f].count (mask)) re res[n][zero][f][mask];
	ll cur = 0;
	for (int t = int (zero); t < 10; t++)
		if (f || t <= q[n - 1]) {
			ll tmp = 0;
			for (int j = 0; j < m; j++)
				if (((mask >> j) & 1) && w[j][t] != -1)
					tmp |= eps[w[j][t]];
			cur += go (n - 1, 0, f | int (t < q[n - 1]), tmp);
		}
//	printf ("%d %d %I64d = %I64d %d\n", n, f, mask, cur, (int)((mask >> aut.se) & 1));
	re res[n][zero][f][mask] = cur;
}

ll calc (ll n) {
	if (n == 0) re 0;
	r = 0;
	while (n) {
		q[r++] = n % 10;
		n /= 10;
	}
	for (int i = 0; i <= r; i++) {
		res[i][0][0].clear ();
		res[i][0][1].clear ();
		res[i][1][0].clear ();
		res[i][1][1].clear ();
	}	
	ll ans = go (r, 1, 0, eps[aut.fi]);
	for (int i = 1; i < r; i++) ans += go (i, 1, 1, eps[aut.fi]);
	re ans;
}

#ifdef PARALLEL
int main (int argv, char **argc) {
	if (argv < 4) {
		printf ("wrong command line\n");
		re 0;
	}
	int PART = stoi (argc[1]);
	int NUM = stoi (argc[2]);
	freopen (argc[3], "r", stdin);
	freopen (argc[4], "w", stdout);
#else
int main () {
#endif
	int tt;
	cin >> tt;
#ifdef PARALLEL
	int CNT = (tt + NUM - 1) / NUM;
#endif	
	for (int it = 1; it <= tt; it++) {
		cin >> L >> R;
		cin >> s;
		int r = 0;
		n = sz (s);
		for (int i = 0; i < n; i++)
			if (s[i] == '(')
				q[r++] = i;
			else
			if (s[i] == ')') {
				r--;
				p[i] = q[r];
				p[q[r]] = i;
			}
#ifdef PARALLEL
		if ((it - 1) >= PART * CNT && (it - 1) < (PART + 1) * CNT) {
#endif
			m = 0;
			aut = build (0, n - 1);
			assert (m <= 60);
			for (int i = 0; i < m; i++) {
				memset (was, 0, sizeof (was));
				int l = 0, r = 1;
				q[0] = i;
				was[i] = 1;
				while (l < r) {
					int x = q[l++];
					eps[i] |= (ll)1 << x;
					for (int j = 0; j < sz (v[x]); j++)
						if (!was[v[x][j]]) {
							q[r++] = v[x][j];
							was[v[x][j]] = 1;
						}	
				}
			}
			ll ans = calc (R) - calc (L - 1);
			cout << "Case #" << it << ": " << ans;
			cout << endl;
#ifdef PARALLEL
			fprintf (stderr, "%d / %d = %.2f | %.2f\n", it - PART * CNT, CNT, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / (it - PART * CNT) * CNT) / CLOCKS_PER_SEC);
		}	
#else
			fprintf (stderr, "%d / %d = %.2f | %.2f\n", it, tt, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / it * tt) / CLOCKS_PER_SEC);
#endif
	}
	return 0;
}