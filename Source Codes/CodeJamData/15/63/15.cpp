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


int n, F;
char buf[22], s[1000010];


ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

void diff(ll A, ll B, ll& Ar, ll& Br) {
    ll g = gcd(B, 1000000);
    ll den = B / g * 1000000;
    ll num = (A * 1000000 - B * F) / g;
    if (num < 0) num = -num;
    Ar = num; Br = den;
}

bool cmp(ll A1, ll B1, ll A2, ll B2) {
    return A1 * B2 < A2 * B1;
}

void solve() {
    scanf("%d %s", &n, buf);
    assert(strlen(buf) == 8);
    sscanf(buf + 2, "%d", &F);
    if (buf[0] == '1') F = 1000000;
    scanf("%s", s);
    assert(int(strlen(s)) == n);
    int ans = -1;
    ll Ab = -1, Bb = -1, A1, B1;
    forn(i, n) {
        int cnt = 0;
        for (int j = i; j < n; j++) {
            cnt += s[j] - '0';
            diff(cnt, j - i + 1, A1, B1);
            if (Ab == -1 || cmp(A1, B1, Ab, Bb)) {
                Ab = A1, Bb = B1;
                ans = i;
                // printf("%d: %d/%d, diff %lld/%lld\n", ans, cnt, j - i + 1, Ab, Bb);
                // break;
            }
        }
    }
    printf("%d\n", ans);
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
