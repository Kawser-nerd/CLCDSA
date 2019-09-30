#include <cstdio>
#include <numeric>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>
#include <deque>
#include <cassert>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define fill(x,y) memset(x,y,sizeof(x))
#define prev PREV
#define j0 j1347829
#define j1 j234892
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

const int mul1 = 17239;
const int mul2 = 239017;
const int mod = 1000*1000*1000 + 7;

int n;
int m;

vi v[10000];
string s[10000];
int cnt[10000];
int p1[100001];

ii can (int x, int p) {
	cnt[x] = 1;
	vector<pair<ii, int> > w;
	for (int i = 0; i < sz (v[x]); i++) {
		int y = v[x][i];
		if (y == p) continue;
		ii tmp = can (y, x);
		w.pb (mp (tmp, cnt[y]));
	}
	sort (all (w));
	int ch = s[x][0];
	int cur = 0, cnt = 0;
	for (int i = 0; i < sz (w); i++) {
		::cnt[x] += 2 + w[i].se;
		ch = ((ll)ch * mul1 + '>');
		ch = ((ll)ch * p1[w[i].se] + w[i].fi.fi);
		ch = ((ll)ch * mul1 + '<');
		cur ^= 1;
		if (i + 1 == sz (w) || w[i + 1] != w[i]) {
			if (w[i].fi.se)
				cnt += cur;
			else
			if (cur) re mp (ch, 0);
			cur = 0;
		}
	}
	if (cnt <= 1 + int (x == p)) re mp (ch, 1);
	re mp (ch, 0);
}

int can2 (int a, int b) {
	vector<pair<ii, int> > w;
	w.pb (mp (can (a, b), cnt[a]));
	w.pb (mp (can (b, a), cnt[b]));
	int cur = 0, cnt = 0;
	for (int i = 0; i < sz (w); i++) {
		cur ^= 1;
		if (i + 1 == sz (w) || w[i + 1] != w[i]) {
			if (w[i].fi.se)
				cnt += cur;
			else
			if (cur) re 0;
			cur = 0;
		}
	}
	if (cnt <= 2) re 1;
	re 0;
}

int main (int argc, char **argv) {
	p1[0] = 1;
	for (int i = 1; i <= 100000; i++) p1[i] = ((ll)p1[i - 1] * mul1) % mod;
	int procnum = 0, procall = 1;
	if (argc > 2) {
		procall = 0;
		for (int i = 0; argv[1][i]; i++) procnum = procnum * 10 + argv[1][i] - '0';
		for (int i = 0; argv[2][i]; i++) procall = procall * 10 + argv[2][i] - '0';
		freopen ((string (argv[1]) + ".in").c_str (), "r", stdin);
		freopen ((string (argv[1]) + ".out").c_str (), "w", stdout);
	}
	double start = clock ();
	int tt, CNT = 0;
	cin >> tt;
	int ALL = (tt + procall - 1) / procall;
	for (int it = 0; it < tt; it++) {
		double current = clock ();

		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> s[i];
			v[i].clear ();
		}	
		for (int i = 0; i < n - 1; i++) {
			int a, b;
			cin >> a >> b; a--; b--;
			v[a].pb (b);
			v[b].pb (a);
		}
		
		if (it % procall != procnum) continue;
		
		int ok = 0;
		for (int i = 0; i < n; i++) {
			if (can (i, i).se) {
				ok = 1;
				break;
			}
		}	

		if (!ok)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < sz (v[i]); j++)
				if (v[i][j] > i)
					if (can2 (i, v[i][j])) {
						ok = 1;
						break;
					}	

		cout << "Case #" << it + 1 << ": " << (ok ? "SYMMETRIC" : "NOT SYMMETRIC");
		cout << endl;
		CNT++;
		cerr << it + 1 << " / " << tt << " = " << (clock () - current) / CLOCKS_PER_SEC << " " << (clock () - start) / CLOCKS_PER_SEC / CNT * ALL << endl;
	}
    return 0;
}