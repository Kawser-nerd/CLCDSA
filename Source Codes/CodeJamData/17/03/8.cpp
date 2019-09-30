#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
typedef long long ll;
#define rep(i, a, b) for (int i = a; i <= b; ++ i)
const int N = 1000005;
using namespace std;
int top, T; ll p[N], n, m;
map <ll, ll> h;
void push(ll x) {
    p[top ++] = x, push_heap(p, p + top);
}
void pop() {
    pop_heap(p, p + top), -- top;
}
int main() {
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
    scanf("%d", &T);
    rep(cas, 1, T) {
        scanf("%lld%lld", &n, &m);
        top = 0, h[n] = 1, push(n);
        for ( ; top; ) {
            ll u = p[0], tmp = h[u]; 
            h[u] -= tmp, pop();

            m -= tmp;
            if (m <= 0) {
                printf("Case #%d: %lld %lld\n", cas, u / 2, u - u / 2 - 1);
                break ;
            }
            ll v = u / 2;
            if (!h[v]) push(v); h[v] += tmp;
            v = u - u / 2 - 1;
            if (!h[v]) push(v); h[v] += tmp;
        } 
        rep(i, 0, top - 1) h[p[i]] = 0;
    }
    return 0;
}