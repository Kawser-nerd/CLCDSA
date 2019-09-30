#include <cstdio>
#include <iostream>
#include <sstream>

#include <string>
#include <cstring>

#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <utility>

#include <algorithm>
#include <cstdlib>
#include <numeric>

#include <climits>
#include <cmath>

#include <chrono>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vl = vector<long>;
using vll = vector<ll>;
using vd = vector<double>;
using pii = pair<int, int>;
using pli = pair<long, int>;
using plli = pair<ll, int>;
using pdi = pair<double, int>;
using pllll = pair<ll, ll>;
using pdd = pair<double, double>;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

const long MAXN = 200010;
const ll MODP = 1e09 + 7;

struct Node {
    string name;
    int count;
    Node *parent, *l_c, *r_c;
};

ll fac[MAXN], facinv[MAXN], inv[MAXN];
ll Combination(int n, int k) {
    if (k < 0 || k > n) { return 0; }
    return (((fac[n] * facinv[k]) % MODP) * facinv[n-k]) % MODP;
}

int main() {
    inv[1] = 1;
    fac[0] = 1;
    facinv[0] = 1;
    for(int i = 2; i < MAXN; i++) {
        inv[i] = MODP - (MODP / i) * inv[MODP % i] % MODP;
    }
    for(int i = 1; i < MAXN; i++) {
        fac[i] = (fac[i - 1] * i) % MODP;
        facinv[i] = (facinv[i - 1] * inv[i]) % MODP;
    }
    ll ans = 0;
    int h, w, a, b;
    scanf("%d %d %d %d", &h, &w, &a, &b);
    int s = b + h - a - 1;
    int t = w + a - b - 1;
    for (int i = 0; i < w - b; i++) {
        if (b + i > s) { break; }
        ans = (ans + (Combination(s, b + i) * Combination(t, a + i)) % MODP) % MODP;
    }
    printf("%lld\n", ans);

    return 0;
}