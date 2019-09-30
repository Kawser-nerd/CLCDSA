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

const ll MAX = 5e12;

int n;
int m;
ll x[500];
vi q;
int was[500];
map<ll, int> all;

int main () {
	int tt;
	cin >> tt;
	for (int it = 1; it <= tt; it++) {

	        scanf ("%d", &n);
	        for (int i = 0; i < n; i++) scanf ("%I64d", &x[i]);
	        sort (x, x + n);
	        reverse (x, x + n);
		cout << "Case #" << it << ":" << endl;
		memset (was, 0, sizeof (was));
		all.clear ();
		int i = 0, step, last = -1;
		ll cur = 0;
		q.clear ();
		while (true) {
			int j;
			while (true) {
				j = rand () % n;
				int ok = 1;
				for (int k = 1; k <= 10 && ok; k++)
					if (i - k >= 0 && q[i - k] == j)
						ok = 0;
				if (ok) break;
			}
			i++;
			q.pb (j);
			if (was[j]) {
				was[j] = 0;
				cur -= x[j];
			} else {
				was[j] = 1;
				cur += x[j];
			}
//			cout << cur << endl;
			if (all.find (cur) != all.end ()) {
				step = all[cur];
				break;
			}	
			all[cur] = i;
		}
		ll a = 0, b = 0;
		for (int j = 0; j < n; j++)
			if (was[j]) {
				a += x[j];
				printf ("%I64d ", x[j]);
			}	
		printf ("\n");
		memset (was, 0, sizeof (was));
		for (int k = 0; k < step; k++) was[q[k]] ^= 1;
		for (int j = 0; j < n; j++)
			if (was[j]) {
				b += x[j];
				printf ("%I64d ", x[j]);
			}	
		printf ("\n");
		cerr << it << " " << i << " " << step << " " << a - b << endl;
	}
	return 0;
}