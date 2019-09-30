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

const int TT = 500;

int n;
int m, f;
set<ii> all;
ii v[200];
int cnt[2000001];
int res[2000001];

int main () {
	int tt;
	cin >> tt;
	for (int it = 1; it <= tt; it++) {

		scanf ("%d%d%d", &m, &f, &n);
		for (int i = 0; i < n; i++) {
			scanf ("%d%d", &v[i].se, &v[i].fi);
			all.insert (mp (v[i].se, v[i].fi));
		}
		sort (v, v + n);
		int sum = f, j = 0;
		for (int i = 0; i <= m; i++) {
			int cur = m + 1;
			if (!all.empty ()) cur = all.begin()->fi;
			sum = min (sum + cur, m + 1);
			cnt[i] = sum;
			while (j < n && v[j].fi == i) all.erase (mp (v[j].se, v[j].fi)), j++;
		}

		res[0] = 0;
		j = 0;

		for (int i = 1; i <= m; i++) {
			res[i] = 0;
			while (cnt[j + 1] <= i && res[i - cnt[j]] + j + 1 <= res[i - cnt[j + 1]] + j + 2) j++;
			for (int t = max (j - TT, 0); t <= min (j + TT, m); t++)
				if (i >= cnt[t] && res[i - cnt[t]] + t + 1 >= res[i]) {
					j = t;
					res[i] = max (res[i], res[i - cnt[t]] + t + 1);
				}	
		}
		
		cout << "Case #" << it << ": " << res[m];

		cout << endl;
		cerr << it << endl;
	}
	return 0;
}