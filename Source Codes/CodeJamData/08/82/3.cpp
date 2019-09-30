#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <cassert>
#include <cmath>
#include <queue>
#include <algorithm>
#include <string>
#include <utility>
#include <sstream>

using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
typedef long long int64;

const double EPS = 1E-8;

#define N 310

int l[N], r[N], n, c[N];

map<string, int> id;

vector<pair<int, int> > col[N];

pair<int, int> a[N];
int cc;


int getId(string s) {
	if (!id.count(s)) {
		int ans = (int)id.size();
		id[s] = ans;
		return ans;
	}
	return id[s];
}

int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	char buf[1000];
	string ss;
	int tk;
	scanf("%d\n", &tk);
	int ans;
	for(int tc = 1; tc <= tk; ++tc) {
		scanf("%d", &n);
		id.clear();
		forn(i, N)
			col[i].clear();
		forn(i, n) {
			scanf("%s %d %d", buf, &l[i], &r[i]);
			ss = buf;
			c[i] = getId(ss);
			if (l[i] > r[i]) swap(l[i], r[i]);
			col[c[i]].pb(mp(l[i], -r[i]));
		}
		ans = INT_MAX;
		int m = (int) id.size();
		forn(c1, m)
			forn(c2, c1 + 1)
				forn(c3, c2 + 1) {
					cc = 0;
					forn(i, col[c1].size())
						a[cc++] = col[c1][i];
					forn(i, col[c2].size())
						a[cc++] = col[c2][i];
					forn(i, col[c3].size())
						a[cc++] = col[c3][i];
					sort(a, a + cc);
					if (a[0].first != 1) continue;
					int curp = -a[0].second, cura = 1;
					for(int i = 1; i < cc; ++i) {
						int mx = 0;
						if (curp == 10000) break;
						if (cura >= ans) break;
						while (i < cc && a[i].first <= curp + 1) {
							mx = max(mx, -a[i].second);
							++i;
						}
						--i;
						if (mx == 0) {
							cura = INT_MAX;
							break;
						}
						curp = mx;
						++cura;
					}
					if (curp == 10000) ans = min(ans, cura);
				}
		if (ans == INT_MAX) printf("Case #%d: IMPOSSIBLE\n", tc);
		else printf("Case #%d: %d\n", tc, ans);
		cerr << tc << endl;
	}

	return 0;
}