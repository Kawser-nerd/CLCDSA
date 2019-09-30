#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

const int len = 64;
const int base = 10;

struct num
{
    int a[len];

    num(char *s = "")
    {
        memset(a, 0, sizeof(a));
        int n = strlen(s) - 1;
        for (int i=0; i<=n; i++)
            a[i] = s[n-i] - '0';
    }

    bool operator <(const num &other) const
    {
        for (int i=len-1; i>=0; i--)
            if (a[i] != other.a[i])
                return a[i] < other.a[i];
        return false;
    }

    num operator -(const num &other) const
    {
        num res = *this;

        for (int i=0; i<len; i++)
        {
            res.a[i] -= other.a[i];
            if (res.a[i] < 0)
            {
                res.a[i] += base;
                res.a[i+1]--;
            }
        }

        return res;
    }

    num operator %(const num &other) const
    {
        num res = *this;
        num tmp = other;

        for (; tmp < res;)
        {
            for (int i=len-1; i; i--)
                tmp.a[i] = tmp.a[i-1];
            tmp.a[0] = 0;
        }

        for (; !(tmp < other);)
        {
            for (; !(res < tmp);)
                res = res - tmp;
            for (int i=0; i<len-1; i++)
                tmp.a[i] = tmp.a[i+1];
        }

        return res;
    }

    bool operator !() const
    {
        for (int i=0; i<len; i++)
            if (a[i])
                return false;
        return true;
    }
} a[1024];

void out(num n)
{
    int i;
    for (i=len-1; i && !n.a[i]; i--);
    for (; i>=0; i--)
        cout << n.a[i];
    cout << endl;
}

num gcd(num a, num b)
{
    return !!b ? gcd(b, a%b) : a;
}

char s[128];

int main()
{
    int t;
    cin >> t;
    for (int tt=1; tt<=t; tt++)
    {
        int n;
        cin >> n;

        for (int i=0; i<n; i++)
        {
            cin >> s;
            a[i] = num(s);
        }

        sort(a, a+n);

        num res = a[1]-a[0];

        for (int i=2; i<n; i++)
            res = gcd(res, a[i]-a[i-1]);

        num ans = a[0] % res;
        if (!!ans)
            ans = res - ans;

        cout << "Case #" << tt << ": ";
        out(ans);
    }
    return 0;
}
