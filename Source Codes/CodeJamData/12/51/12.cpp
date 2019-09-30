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
int x[1000];
int y[1000];
vi v, w;

bool l1 (int i, int j) {
	re 100 * x[i] + (100 - y[i]) * x[j] < 100 * x[j] + (100 - y[j]) * x[i] || (100 * x[i] + (100 - y[i]) * x[j] == 100 * x[j] + (100 - y[j]) * x[i] && i < j);
}

int main () {
	int tt;
	cin >> tt;
	for (int it = 1; it <= tt; it++) {

		scanf ("%d", &n);
		for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
		v.clear ();
		w.clear ();
		for (int i = 0; i < n; i++) {
			scanf ("%d", &y[i]);
			if (y[i] == 0) v.pb (i); else w.pb (i);
		}	
		sort (all (w), l1);
		sort (all (v));
		cout << "Case #" << it << ": ";

		for (int i = 0; i < sz (w); i++) printf ("%d ", w[i]);
		for (int i = 0; i < sz (v); i++) printf ("%d ", v[i]);

		cout << endl;
	}
	return 0;
}