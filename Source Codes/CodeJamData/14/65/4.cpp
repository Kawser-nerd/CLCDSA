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

const int T = 1;

ll n, a, b;

ll res[1000000];
            
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
		
		cin >> n >> a >> b;

		if (it % procall != procnum) continue;
		
		res[0] = 1;
		int ans = 0;
		if (n > 1)
		for (int i = 1; ; i++) {
			res[i] = res[i - 1];
			if (i >= a) res[i] = max (res[i], res[i - a] + 1);
			if (i >= b) res[i] = max (res[i], res[i - b] + res[i - a]);
			if (res[i] >= n) {
				ans = i;
				break;
			}
		}

		cout << "Case #" << it + 1 << ": " << ans;
		cout << endl;
		CNT++;
		cerr << it + 1 << " / " << tt << " = " << (clock () - current) / CLOCKS_PER_SEC << " " << (clock () - start) / CLOCKS_PER_SEC / CNT * ALL << endl;
	}
    return 0;
}