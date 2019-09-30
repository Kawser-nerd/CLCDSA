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

int n;
int m;

int cool (const vi& v) {
	for (int i = 0; i < sz (v); i += 2) {
		if (v[i] % 2 == 0 && v[i + 1] == v[i] + 1) continue;
		re 0;
	}
	re 1;
}

vi merge (const vi& v) {
	vi nv;
	for (int i = 0; i < sz (v); i += 2)
		nv.pb (v[i] / 2);
	re nv;
}

ll go (vi v, int cur, int sum) {
	if (sz (v) == 1) re sum;
	vi w;
	for (int i = 0; i < sz (v); i += 2) {
		if (v[i] % 2 == 0 && v[i + 1] == v[i] + 1) continue;
		w.pb (i);
	}
	if (sz (w) == 0) re go (merge (v), cur, sum); else
	if (sz (w) == 1) {
		swap (v[w[0]], v[w[0] + 1]);
		if (cool (v)) re go (merge (v), cur + 1, sum * (cur + 1));
	} else
	if (sz (w) == 2) {
		ll ans = 0;
		for (int a = 0; a < 2; a++)
			for (int b = 0; b < 2; b++) {
				swap (v[w[0] + a], v[w[1] + b]);
				if (cool (v)) ans += go (merge (v), cur + 1, sum * (cur + 1));
				swap (v[w[0] + a], v[w[1] + b]);
			}
		re ans;	
	} else re 0;
}

int main (int argc, char **argv) {
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
		
		scanf ("%d", &n);
		m = 1 << n;
		vi v (m);
		for (int i = 0; i < m; i++) {
			scanf ("%d", &v[i]);
			v[i]--;
		}
		                            
		if (it % procall != procnum) continue;


		cout << "Case #" << it + 1 << ": " << go (v, 0, 1);
		cout << endl;
		CNT++;
		cerr << it + 1 << " / " << tt << " = " << (clock () - current) / CLOCKS_PER_SEC << " " << (clock () - start) / CLOCKS_PER_SEC / CNT * ALL << endl;
	}
    return 0;
}