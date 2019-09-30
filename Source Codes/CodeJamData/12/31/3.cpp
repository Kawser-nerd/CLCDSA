#include <vector>
#include <algorithm>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <ctime>


using namespace std;

#define maxn 1100

vector <int> ne[maxn];
int was[maxn];

bool dfs (int v) {
  if (was[v]) {
  	return true;
  }
  was[v] = 1;
	for (int i = 0; i < (int)ne[v].size(); i++) {
		int u = ne[v][i];
		if (dfs (u)) {
			return true;
		}
	}
	return false;
}

int main (void) {
	int tests_n;
	scanf ("%d", &tests_n);
	for (int test_id = 1; test_id <= tests_n; test_id++) {
		printf ("Case #%d: ", test_id);

		int n;
		scanf ("%d", &n);
		for (int v = 1; v <= n; v++) {
			int vn;
			scanf ("%d", &vn);

			for (int i = 0; i < vn; i++) {
				int u;
				scanf ("%d", &u);
				ne[v].push_back (u);
			}
		}

    bool res = false;
		for (int v = 1; v <= n && !res; v++) {
			memset (was, 0, sizeof (int) * (n + 1));
			res |= dfs (v);
		}

		for (int i = 0; i <= n; i++) {
			ne[i].clear();
		}

		printf ("%s\n", res ? "Yes" : "No");
	}
	return 0;
}