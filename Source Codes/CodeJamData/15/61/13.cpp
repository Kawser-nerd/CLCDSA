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


int n, a[1000010];
int fl[202][1000010], fr[202][1000010];
char s[1000010];


int getMaxC(int L, int R) {
    if (L == R) return a[L];
    int M = (L + R) >> 1;
    int res = a[M];
    if (L <= M - 1) res = max(res, getMaxC(L, M - 1) + a[M]);
    if (M + 1 <= R) res = max(res, getMaxC(M + 1, R) + a[M]);
    return res;
}

void solve() {
    scanf("%s", s);
    n = strlen(s);
    forn(i, n) a[i] = s[i] - '0';

    int maxc = getMaxC(0, n - 1);
    forn(i, n) fl[0][i] = n, fr[0][i] = -1;
    for (int c = 1; c <= maxc; c++) {
        forn(i, n) {
            fl[c][i] = n;
            fr[c][i] = -1;
        }
        forn(i, n) {
            if (a[i] > c) continue;
            int ml = i == 0 ? 0 : fl[c - a[i]][i - 1];
            int mr = i == n - 1 ? n - 1 : fr[c - a[i]][i + 1];
            if (ml > i) ml = i;
            if (mr < i) mr = i;
            fl[c][mr] = min(fl[c][mr], ml);
            fr[c][ml] = max(fr[c][ml], mr);
            // printf("c=%d, i=%d: [%d-%d]\n", c, i, ml, mr);

            if (ml == 0 && mr == n - 1) {
                printf("%d\n", c);
                return;
            }
        }

        // printf("fr: %d ", fr[c][0]);
        for (int i = 1; i < n; i++) {
            fr[c][i] = max(fr[c][i-1], fr[c][i]);
            // printf("%d ", fr[c][i]);
        }
        // printf("\n");
        for (int i = n - 2; i >= 0; i--) {
            fl[c][i] = min(fl[c][i+1], fl[c][i]);
        }
        /*
        printf("fl:");
        forn(i, n) printf(" %d", fl[c][i]);
        printf("\n");
        */
    }
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
