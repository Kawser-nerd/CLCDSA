#include <iostream>
#include <algorithm>

using namespace std;

long long gcd(long long a, long long b)
{
    return b ? gcd(b, a%b) : a;
}

long long a[1<<16];

long long lm[1<<16];
long long gd[1<<16];

long long inf = 1LL<<60;

int main()
{
    int t;

    cin >> t;

    for (int tt=1; tt<=t; tt++)
    {
        int n;
        long long L, H;

        cin >> n >> L >> H;

        for (int i=0; i<n; i++)
            cin >> a[i];

        sort(a, a+n);

        lm[0] = 1;
        for (int i=0; i<n; i++)
        {
            long long d = gcd(lm[i], a[i]);

            if (inf / lm[i] * d / a[i] == 0)
                lm[i+1] = inf;
            else
                lm[i+1] = lm[i] / d * a[i];
        }

        gd[n] = 0;
        for (int i=n-1; i>=0; i--)
            gd[i] = gcd(gd[i+1], a[i]);

        cout << "Case #" << tt << ": ";

        bool f = false;

        for (int i=0; i<=n; i++)
            if (gd[i] % lm[i] == 0 && (gd[i] >= L || i == n) && lm[i] <= H)
            {
                if (i == n)
                {
                    long long q = (L + lm[i] - 1) / lm[i] * lm[i];
                    if (q >= L && q <= H)
                    {
                        cout << q << endl;
                        f = true;
                    }
                    break;
                }

                long long d = gd[i] / lm[i];

                long long ans = inf;

                for (long long x = 1; x*x <= d; x++)
                    if (d % x == 0)
                    {
                        long long q = lm[i] * x;
                        if (q >= L && q <= H)
                        {
                            if (q < ans)
                                ans = q;
                            f = true;
                        }

                        q = lm[i] * (d / x);
                        if (q >= L && q <= H)
                        {
                            if (q < ans)
                                ans = q;
                            f = true;
                        }
                    }                    
                if (f)
                    cout << ans << endl;
                                
                break;
            }

        if (!f)
            cout << "NO" << endl;
    }

    return 0;
}
