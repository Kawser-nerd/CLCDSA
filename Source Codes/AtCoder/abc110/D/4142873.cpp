#include <algorithm>
#include <iostream>
#include <cmath>
#include <map>

using namespace std;

const long long size_max = 1000000;
const long long mod = 1e9 + 7;

long long fac[size_max], inv[size_max], finv[size_max];
bool primes[size_max];

map<long long, long long> p;

long long N, M;

void make_table()
{
    fac[0] = fac[1] = 1LL;
    finv[0] = finv[1] = 1LL;
    inv[1] = 1LL;
    for (int i = 2; i < size_max; i++)
    {
        fac[i] = (fac[i - 1] * i) % mod;
        inv[i] = mod - inv[mod % i] * (mod / i) % mod;
        finv[i] = finv[i - 1] * inv[i] % mod;
    }
}

long long comb(int n, int k)
{
    if (n < k)
        return 0LL;
    if (n < 0 || k < 0)
        return 0LL;
    return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
}

void cntp()
{
    int sqrtm = sqrt(M);
    for (int i = 2; i < sqrtm; i++)
    {
        if(primes[i] == false)
        {
            for (int j = 2; i * j < size_max;j++)
            {
                primes[i * j] = true;
            }
        }
    }

    int m = M;

    for (int i = 2; i <= sqrtm;i++)
    {
        if (primes[i] == true)
        {
            continue;
        }
        while(m % i == 0)
        {
            if(p.find(i) == p.end())
            {
                p.insert(make_pair(i, 1));
            }
            else
            {
                p[i]++;
            }
            m /= i;
        }
    }
    if (m != 1)
    {
        p[m]++;
    }
}

int main()
{
    make_table();
    cin >> N >> M;
    cntp();

    long long ans = 1;

    for (auto const &x : p)
    {
        long long b = x.second;
        ans = (ans * comb(b + N - 1, b)) % mod;
    }
    cout << ans << endl;

    return 0;
}