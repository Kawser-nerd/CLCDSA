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
ll m;
ll x[37];

int main () {
	int tt;
	cin >> tt;
	for (int it = 1; it <= tt; it++) {

		cin >> m >> n;
		memset (x, 0, sizeof (x));
		for (int i = 0; i < n; i++) cin >> x[i];
		sort (x, x + 37);
		double ans = 0;
		ll cur = 0;
		for (int i = 0; i < 37; i++) {
			cur += x[i];
			ll l = 0, r = 1e15;
			while (r - l > 1) {
				ll s = (l + r) / 2;
				ll tmp = 0;
				for (int j = 0; j < 37; j++)
					if (j <= i) 
						tmp += max ((ll)0, s - x[j]);
					else
						tmp += max ((ll)0, (s + 1) - x[j]);
				if (tmp <= m) l = s; else r = s;
			}
			ll tmp = 0;
			for (int j = 0; j < 37; j++)
				if (j <= i) 
					tmp += max ((ll)0, l - x[j]);
				else
					tmp += max ((ll)0, (l + 1) - x[j]);
//			printf ("%d = %I64d %I64d\n", i + 1, cur, l);
			if (l >= x[i]) ans = max (ans, ((ll)(i + 1) * l - cur) * 36 / (i + 1.0) - tmp);
		}		
		cout << "Case #" << it << ": ";
		printf ("%.10f", ans);

		cout << endl;

		cerr << it << " / " << tt << " " << clock () << endl;
	}
	return 0;
}