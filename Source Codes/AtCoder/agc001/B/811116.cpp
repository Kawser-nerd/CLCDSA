#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

static const int INF = 1001001001;

using namespace std;

long long func(long long a, long long b)
{
    if (b % a == 0) {
        return 2*a*(b/a) - a;
    } else {
        return 2*a*(b/a) + func(b%a, a);
    }
}

int main()
{
    long long n, x, ans;
    cin >> n >> x;
    if (2*x < n) {
        ans = n + func(x, n - x);
    } else {
        ans = n + func(n - x, x);
    }
    cout << ans << endl;
    return 0;
}