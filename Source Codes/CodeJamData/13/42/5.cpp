#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
using namespace std;

long long p2(int n)
{
    return 1LL << n;
}

long long f1(int n, long long p)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return p - 1;
    if (p <= p2(n - 1))
        return 0;
    return min(2 * (f1(n - 1, p - p2(n - 1)) + 1), p2(n) - 1);
}

long long f2(int n, long long p)
{
    if (p == p2(n))
        return p - 1;
    return p2(n) - f1(n, p2(n) - p) - 2;
}

void work()
{
    int n;
    long long p;
    cin >> n >> p;
    cout << f1(n, p) << " " << f2(n, p);
}

int main()
{
    freopen("b2.in", "r", stdin);
    freopen("b2.out", "w", stdout);

    int t2;
    cin >> t2;
    for (int t1 = 1; t1 <= t2; ++t1) {
        printf("Case #%d: ", t1);
        work();
        printf("\n");
    }
    
    return 0;
}
