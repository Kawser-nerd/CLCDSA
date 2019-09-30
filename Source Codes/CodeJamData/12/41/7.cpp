#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <memory.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

int n, D, d[10010], l[10010], u[10010];

bool solve() {
    scanf("%d", &n);
    forn(i, n) scanf("%d %d", &d[i], &l[i]), u[i] = 0;
    scanf("%d", &D);
    u[0] = d[0];
    forn(i, n) {
        if (u[i] == 0) continue;
        if (u[i] > l[i]) u[i] = l[i];
        if (d[i] + u[i] >= D) return true;
        int j = i + 1;
        while (j < n && d[j] <= d[i] + u[i]) {
            if (u[j] < d[j] - d[i]) u[j] = d[j] - d[i];
            j++;
        }
    }
    return false;
}

int main() {
    int tc;
    scanf("%d", &tc);
    for (int q = 1; q <= tc; q++) {
        printf("Case #%d: ", q);
        if (solve()) printf("YES\n");
        else printf("NO\n");
    }
}
