#ifndef LOCAL_BOBER
#pragma comment(linker, "/STACK:134217728")
#endif

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#include <stack>
#include <sstream>
#include <cstring>
#include <numeric>
#include <ctime>

#define re return
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int) (x).size())
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define y0 y32479
#define y1 y95874
#define fill(x, y) memset(x, y, sizeof(x))
#define sqr(x) ((x) * (x))
#define prev prev239
#define next next239
#define hash hash239
#define rank rank239
#define sqrt(x) sqrt(abs(x))

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef long long ll;
typedef double D;
typedef long double LD;

template<class T> T abs(T x) {return x > 0 ? x : -x;}

int n;
int m;

int best;
int ans;

map<string, int> id;

string str;
string s[10000];
int mask[26][10000];

void calc_mask(int p) {
	rep(i, 26)
		mask[i][p] = 0;
	rep(i, sz(s[p]))
		mask[s[p][i] - 'a'][p] += (1 << i);
}

void go(vi v, int p, int bonus) {
/*	cout << p << ' ' << str[p] << ' ' << bonus << endl;
	rep(i, sz(v))
	cout << v[i] << ' ';
	cout << endl << endl;*/

	if (!sz(v))
		re;
	if (sz(v) == 1) {
		//cout << "o: " << bonus << ' ' << best << ' ' << v[0] << endl;
		if (bonus > best) {
			best = bonus;
			ans = v[0];
		}
		if (bonus >= best)
			ans = min(ans, v[0]);
		re;
	}

	int c = str[p] - 'a';
	int f = 0;
	rep(i, sz(v))
	if (mask[c][v[i]])
		f = 1;
	if (!f) {
		go(v, p + 1, bonus);
		re;
	}

//	cout << "c = " << c << " f = " << f << endl;
//	cout << mask[0][1] << ' ' << mask[0][2] << endl;

	map<int, int> mm;
	int t = 0;
	vvi vv;
	rep(i, sz(v)) {
		int x = v[i];
		int m = mask[c][x];
		if (mm.count(m) == 0) {
			mm[m] = t++;
			vi z;
			vv.pb(z);
		}
		int o = mm[m];
		vv[o].pb(x);
	}

	rep(i, sz(vv))
		go(vv[i], p + 1, bonus + (mask[c][vv[i][0]] == 0));
}

int main() {
#ifdef LOCAL_BOBER
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int tc;
	cin >> tc;
	rep(tt, tc) {
		printf("Case #%d: ", tt + 1);

		cin >> n >> m;

		vi v[11];

		id.clear();
		rep(i, n) {
			cin >> s[i];
			v[sz(s[i])].pb(i);
			calc_mask(i);
		}

		rep(i, m) {
			cin >> str;
			best = -1;

			rep(j, 11)
			if (sz(v[j]) > 0)
				go(v[j], 0, 0);
			cout << s[ans] << ' ';
		}
		cout << endl;
	}

	re 0;
}

