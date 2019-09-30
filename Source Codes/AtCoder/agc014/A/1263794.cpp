// jimjam
#include <cstdio>
using ll = long long;

ll a,b,c,t;

int main() {
    scanf("%lld %lld %lld", &a, &b, &c);
    t = a+b+c;
    if (a%2 == 0 && b%2 == 0 && c%2 == 0 && a==b && a == c) {
        printf("-1\n");
        return 0;
    }

    ll ans = 0;
    while (a%2 == 0 && b%2 == 0 && c%2 == 0) {
        a = (t-a)/2;
        b = (t-b)/2;
        c = (t-c)/2;
        ans++;
    }
    printf("%lld\n", ans);
}