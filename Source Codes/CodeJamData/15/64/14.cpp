#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <iostream>
#include <cassert>
#include <ctime>
#include <memory.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define pb push_back
#define DBG(x) cerr << #x << ": " << x << endl;
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;


int n, m, k;
vector<int> g[110];
int d[110], p[110];
bool blocked[110];

void bfs() {
    vector<int> q;
    q.push_back(0);
    memset(d, 0xff, sizeof(d));
    d[0] = 0;
    size_t qb = 0;

    while (qb < q.size()) {
        int x = q[qb++];
        for (int y : g[x])
            if (d[y] == -1 && !blocked[y]) {
                d[y] = d[x] + 1;
                q.pb(y);
                p[y] = x;
            }
    }
}

void solve() {
    int u, v;
    scanf("%d %d %d", &n, &m, &k);
    forn(i, n) g[i].clear(), blocked[i] = 0;
    forn(i, m) {
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    bfs();
    int initd = d[n - 1];
    k--;
    while (k) {
        bfs();
        // printf("k = %d, initd = %d, curd = %d\n", k, initd, d[n-1]);
        if (d[n - 1] > initd || d[n - 1] == -1) {
            printf("%d\n", initd + 2);
            return;
        }
        int z = n - 1;
        while (z != 0) {
            if (z != n - 1) blocked[z] = true;
            // printf("k = %d, blocked %d\n", k, z);
            z = p[z];
        }
        k--;
    }
    bfs();
    if (d[n - 1] > initd || d[n - 1] == -1) {
        printf("%d\n", initd + 2);
        return;
    }
    printf("%d\n", initd + 1);
}

int main() {
	int tc;
    auto start = clock();
	scanf("%d", &tc);
	for (int q = 1; q <= tc; q++) {
		printf("Case #%d: ", q);
		solve();
		fprintf(stderr, "Case %d done, %.3f sec.\n",
                q, double(clock() - start) / CLOCKS_PER_SEC);
	}
	return 0;
}
