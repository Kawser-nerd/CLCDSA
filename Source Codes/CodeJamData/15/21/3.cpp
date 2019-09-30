#include <cstdio>
#include <algorithm>
#include <memory.h>
using namespace std;

typedef long long llong;


llong rev(llong x)
{
    llong ans = 0;
    while (x > 0)
        ans = 10 * ans + (x % 10), x /= 10;
    return ans;
}

llong pw10[15];

void solve(int cs)
{
    llong n;
    scanf("%lld", &n);
    llong c = 1;
    llong ans = 0;
    int p = 0;
    while (10 * c <= n)
    {
        if (p == 0)
            ans += 9, p++, c *= 10;
        else if (p % 2 == 1)
            ans += 2 * pw10[(p + 1) / 2] - 1, p++, c *= 10;
        else
            ans += pw10[p / 2] + pw10[p / 2 + 1] - 1, p++, c *= 10; 
    }
    if (c != ans)
    {
        bool dec = n % 10 == 0;
        if (dec)
            n--;
        llong ans1 = ans + (n - c);
        llong ansr = ans1;
        llong nn = rev(n);
        for (int i = 1; i <= p; i++)
        {
            llong a = nn % pw10[i];
            llong b = nn / pw10[i];
            ansr = min(ansr, ans + a + rev(b));
        }
        ans = ansr + dec;
    }
    printf("Case #%d: %lld\n", cs, ans + 1);
}

int main()
{
    int T;
    scanf("%d", &T);
    pw10[0] = 1;
    for (int i = 1; i < 15; i++)
        pw10[i] = pw10[i - 1] * 10ll;
    for (int i = 0; i < T; i++)
        solve(i + 1);
}
