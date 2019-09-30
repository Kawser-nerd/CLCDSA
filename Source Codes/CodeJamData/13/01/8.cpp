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
const int n = 4;
char a[5][5];
const int dx[] = {1, 0, 1, 1};
const int dy[] = {0, 1, 1, -1};
bool win(char c) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < 4; k++) {
				int cnt = 0;
				for (int go = 0; i + go * dx[k] >= 0 && i + go * dx[k] < n && j + go * dy[k] >= 0 && j + go * dy[k] < n; go++) {
					if (a[i + go * dx[k]][j + go * dy[k]] == c || a[i + go * dx[k]][j + go * dy[k]] == 'T') {
						cnt++;
					} else {
						break;
					}
				}
				if (cnt >= 4) return true;
			}
		}
	}
	return false;
}
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
		for (int i = 0; i < n; i++) {
			scanf("%s", a[i]);
		}
		int ke = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] == '.') {
					ke++;
				}
			}
		}
		if (win('X')) {
			printf("X won\n");
			continue;
		}
		if (win('O')) {
			printf("O won\n");
			continue;
		}
		if (ke > 0) {
			printf("Game has not completed\n");
			continue;
		} 
		printf("Draw\n");
	}
	#ifdef home
		eprintf("Time: %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
	#endif
	return 0;
}
 