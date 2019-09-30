#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

long long int gcd (long long int n, long long int m)
{
    long long int maxn = max(n,m);
    long long int minn = min(n,m);
    if (maxn % minn == 0) {
        return minn;
    }
    return gcd(minn, maxn % minn);
}

long long int lcm (long long int n, long long int m)
{
    long long int lcmn = gcd(n, m);
    return n * m / lcmn;
}
int main ()
{
    long long int n , m;
    string s, t;
    cin >> n >> m >> s >> t;
    long long int l = lcm(n,m);
    long long int f = lcm(l/n, l/m);
    bool good_str = true;
    long long int comp_rate_s = l / n;
    long long int comp_rate_t = l / m;
    long long int gcdn = gcd(n,m);
    long long int itr_judge = lcm(n / gcdn, m / gcdn);
    for (int i = 0; i < n; ++i) {
        if (i * comp_rate_s % itr_judge == 0) {
            if (s[i] != t[i * m / n]) {
                good_str = false;
                break;
            }
        }
    }
    cout << (good_str ? l : -1);
}