#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <ctime>
#include <cassert>

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define forit(it,v) for(typeof((v).begin()) it = v.begin() ; it != (v).end() ; ++it)
#define eprintf(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(),a.end()

using namespace std;

typedef long long ll;
typedef double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;

const int inf = (int)1e9;
const ld eps = 1e-9;


#define TASK "a"
int n, m;
int a[200][200];
int b[200][200];
int main()
{
	#ifdef home
		assert(freopen(TASK".in", "r", stdin));
		assert(freopen(TASK".out", "w", stdout));
	#endif
	int T;
	scanf("%d", &T);
	for (int ti = 0; ti < T; ti++) {
		printf("Case #%d: ", ti + 1);
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%d", &a[i][j]);
				b[i][j] = 100;
			}
		}
		for (int i = 0; i < n; i++) {
			int mx = 0;
			for (int j = 0; j < m; j++) {
				mx = max(mx, a[i][j]);
			}
			for (int j = 0; j < m; j++) {
				b[i][j] = min(b[i][j], mx);
			}
		}
		for (int i = 0; i < m; i++) {
			int mx = 0;
			for (int j = 0; j < n; j++) {
				mx = max(mx, a[j][i]);
			}
			for (int j = 0; j < n; j++) {
				b[j][i] = min(b[j][i], mx);
			}
		}
		bool can = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] != b[i][j]) {
					can = false;
				}
			}
		}
		if (can) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	#ifdef home
		eprintf("Time: %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
	#endif
	return 0;
}
 