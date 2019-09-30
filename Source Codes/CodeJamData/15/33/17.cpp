#pragma comment(linker, "/STACK:102400000,102400000")
#include <iostream>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <map>
#include <functional>
#include <queue>
#include <vector>
#include <cstdlib>
#include <string>
#include <set>
#include <ctime>
using namespace std;

#define PII pair<int,int> 
#define MP make_pair
#define FI first
#define SE second
#define PB push_back
#define lid (id << 1)
#define rid (id << 1 | 1)
#define MID(a, b) ((a + b) >> 1)

const int N = 10010;
const int INF = 1000000000;
const int Mod = 1000000007;
const int maxn = 10;
const double PI = acos(-1.0);
const double eps = 1e-6;


long long a[N];
int C, n, V;

void solve() {
    scanf("%d%d%d", &C, &n, &V);
    for(int i = 1; i <= n; i++) {
        scanf("%lld", a + i);
    }
    long long ans = 0, now = 0;
    for(int i = 1; i <= n; i++) {
        while(now + 1 < a[i]) {
            ans ++;
            now += (now + 1) * C;
        }
        now += a[i] * C;
    }
    while(now < V) {
        ans ++;
        now += (now + 1) * C;
    }
    cout << ans << endl;
}

int main() {
    freopen("C2.in", "r", stdin);
    freopen("C2.out", "w", stdout);  
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++) {
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}
