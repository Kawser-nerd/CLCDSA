#include <iostream>
#include <cmath>
#include <vector>

#define mod 1000000007

typedef long long ll;

using namespace std;

// http://www.tbasic.org/reference/old/ExEuclid.html
// https://qiita.com/rintaromasuda/items/be6510090af04bad833d
ll modinverse(ll a, ll m) {
    ll x = 0, y = 1, gcd = m;
    ll px = 1, py = 0, pgcd = a;
    ll temp = 0;
    ll quotient;

    while (gcd > 0) {
        quotient = pgcd / gcd;

        temp = x;
        x = px - quotient * temp;
        px = temp;

        temp = y;
        y = py - quotient * temp;
        py = temp;

        temp = gcd;
        gcd = pgcd - quotient * temp;
        pgcd = temp;
    }
    if (px < 0) {
        px += m;
    }

    return px;
}

ll combination(int n, int r) {
    int i;
    ll u, d, inverse;

    u = 1;
    for (i = n; i > n - r; i--) {
        u = (u * i) % mod;
    }
    // d = 1;
    // for (i = r; i > 1; i--) {
    //     d *= i;
    // }
    // inverse = modinverse(d, mod);
    // return (u * inverse) % mod;
    d = u;
    for (i = r; i > 1; i--) {
        inverse = modinverse(i, mod);
        d = (d * inverse) % mod;
    }
    return d;
}

int main() {
    int N, M;
    int i;
    int num;
    ll ans;
    int count;
    vector <int> prime = {2};
    bool f;

    cin >> N >> M;

    count = 0;
    for (i = 3; i <= sqrt(M); i += 2) {
        f = true;
        for (int x : prime) {
            if (i % x == 0) {
                f = false;
                break;
            }
        }
        if (f) {
            prime.push_back(i);
        }
    }

    vector <int> c(prime.size(), 0);
    num = M;
    for (i = 0; i < prime.size(); i++) {
        while (num % prime[i] == 0) {
            c[i]++;
            num = num / prime[i];
        }
    }
    if (num != 1) {
        prime.push_back(num);
        c.push_back(1);
    }

    // for (i = 0; i < prime.size(); i++) {
    //     if (c[i] != 0) {
    //         cout << prime[i] << " " << c[i] << endl;
    //     }
    // }

    ans = 1;
    for (i = 0; i < prime.size(); i++) {
        if (c[i] != 0) {
            ans *= combination(c[i] + N - 1, c[i]);
            ans %= mod;
        }
    }
    cout << ans << endl;

    return 0;
}