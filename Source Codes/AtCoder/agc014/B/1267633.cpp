#include <algorithm>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

#ifdef __APPLE__
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...)
#endif

const int N = (int)1e6 + 123;
const int MOD = (int)1e9 + 7;
const int inf = (int)5e8;
const long long infll = (long long)1e17;


int a[N];

void solve() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        --u;
        --v;
        if (u > v) {
            swap(u, v);
        }
        ++a[u];
        ++a[v];
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] % 2) {
            printf("NO\n");
            return;
        }
    }
    printf("YES\n");
}

int main() {
#ifdef __APPLE__
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}