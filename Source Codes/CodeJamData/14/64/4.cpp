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
int was[200];
int inp[200];
string s[200];
int w[200];
int q[200];
int use[200];
int now[200];
int g[200][200];
int o, ct;

int get (int a, int b) {
	if (a == -1 || g[b][a]) re b;
	re a;
}

int go (int x, int y, int f, int len) {
	q[len - 1] = x;
	if (x == y) {
		for (int i = o - 1; i > f; i--)
			w[i + len - 1] = w[i];
		for (int i = 0; i < len; i++) {
			w[f + i] = q[i];
			inp[q[i]] = 1;
		}
		o += len - 1;
		re 1;
	}
	if (inp[x] || was[x] == ct) re 0;
	was[x] = ct;
	for (int i = 0; i < n; i++)
		if (g[i][x] && !use[i] && go (i, y, f, len + 1))
			re 1;
	re 0;
}

int can (int lead) {
	if (lead == m) {
		for (int i = 0; i < n; i++)
			if (!use[i] && !g[lead][i])
				re 0;
		re 1;
	} else {
		memset (inp, 0, sizeof (inp));
		ct++;
		o = 1;
		if (!go (lead, m, 0, 1))
			re 0;
		for (int i = 0; i < n; i++)
			if (!use[i]) {
				int ok = 1; 
				for (int j = 0; j < o; j++) {
					if (w[j] == i || g[w[j]][i]) {
						ok = 0;
						break;
					}
				}
				if (!ok) continue;
//				printf ("%d\n", i);
				ct++;
				ok = 0;
				for (int j = 0; j + 1 < o; j++) {
					inp[w[j + 1]] = 0;
					if (go (i, w[j + 1], j + 1, 1)) {
						ok = 1;
						break;
					} else inp[w[j + 1]] = 1;
				}
				if (!ok) re 0;
/*				printf ("	path: ");
				for (int i = 0; i < o; i++) printf ("%d ", w[i]);*/
			}
		re 1;
	}
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
		
		cin >> n >> m;
		for (int i = 0; i < n; i++)
			cin >> s[i];	

		for (int i = 0; i < n; i++)	
			for (int j = 0; j < n; j++)
				g[i][j] = int (s[i][j] == 'Y');

		if (it % procall != procnum) continue;

    	memset (use, 0, sizeof (use));
    	int ok = 1, lead = -1;
    	for (int i = 0; i < n; i++) {
//    		printf ("%d = %d\n", i, lead);
	    	for (int j = 0; j < n; j++) {
	    		if (use[j]) continue;
	    		if (lead == m && !g[lead][j]) continue;
	    		if (j == m && g[lead][j]) continue;
	    		use[j] = 1;
    			if (can (get (lead, j))) {
//    				printf ("take %d\n", j);
    				lead = get (lead, j);
    				now[i] = j;
    				break;
	    		}
	    		use[j] = 0;
	    	}
	    	if (lead == -1) {
	    		ok = 0;
	    		break;
	    	}
    	}
    	cout << "Case #" << it + 1 << ":";
    	if (!ok) printf (" IMPOSSIBLE"); else {
    		for (int i = 0; i < n; i++)
    			printf (" %d", now[i]);
    	}
		cout << endl;
		CNT++;
		cerr << it + 1 << " / " << tt << " = " << (clock () - current) / CLOCKS_PER_SEC << " " << (clock () - start) / CLOCKS_PER_SEC / CNT * ALL << endl;
	}
    return 0;
}