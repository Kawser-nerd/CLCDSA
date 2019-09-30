#include <iostream>

using namespace std;

int a[1024];
int next[1024];
long long m[1024];
int x[1024];
long long y[1024];

int main()
{
    int t;
    cin >> t;
    for (int tt=1; tt<=t; tt++)
    {
        int r, k, n;
        cin >> r >> k >> n;
        for (int i=0; i<n; i++)
        {
            cin >> a[i];
            m[i] = 0;
        }

        cout << "Case #" << tt << ": ";

        for (next[0]=0; next[0]<n; next[0]++)
        {
            if (m[0] + a[next[0]] > k)
                break;
            m[0] += a[next[0]];
        }

        if (next[0] == n)
        {
            cout << (long long)m[0]*r << endl;
            continue;
        }

        for (int i=1; i<n; i++)
        {
            next[i] = next[i-1];
            m[i] = m[i-1] - a[i-1];
            for (; m[i] + a[next[i]] <= k; next[i]++, next[i] %= n)
                m[i] += a[next[i]];
        }

        int cur = 0;
        long long res = 0;

        for (; r; r>>=1)
        {
            if (r & 1)
            {
                res += m[cur];
                cur = next[cur];
            }

            for (int i=0; i<n; i++)
            {
                y[i] = m[i] + m[next[i]];
                x[i] = next[next[i]];
            }

            for (int i=0; i<n; i++)
            {
                next[i] = x[i];
                m[i] = y[i];
            }
        }

        cout << res << endl;
    }
    return 0;
}
