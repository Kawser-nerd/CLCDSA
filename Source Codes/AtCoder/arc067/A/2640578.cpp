#include <iostream>

#include <map>
#include <cmath>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

using ll = long long;
using ii = pair<ll, ll>;

const ll MOD { 1000000007 };

ll Ep(ll n, ll p)
{
    ll res = 0;

    while (n / p)
    {
        res += n / p;
        n /= p;
    }

    return res;
}

bool is_prime(ll n)
{
    for (ll p = 3; p * p <= n; p += 2)
    {
        if (n % p == 0)
            return false;
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<ll> ds;

    ll res = Ep(N, 2);

    if (res)
        ds.push_back(res);

    for (ll p = 3; p <= N; p += 2)
    {
        if (not is_prime(p))
            continue;

        res = Ep(N, p);

        if (res)
            ds.push_back(res);
    }

    res = 1;

    for (const auto& d : ds)
    {
        res *= (d + 1);
        res %= MOD;
    }

    cout << res << endl;

    return 0;
}