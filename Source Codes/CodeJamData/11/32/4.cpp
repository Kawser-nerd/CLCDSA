#include <iostream>

using namespace std;

long long a[1<<20];
long long d[1<<20];

int main()
{
    int t;
    cin >> t;

    for (int tt=1; tt<=t; tt++)
    {
        cout << "Case #" << tt << ": ";

        int s, n, c;
        long long t;
        cin >> s >> t >> n >> c;

        for (int i=0; i<c; i++)
            cin >> a[i];

        for (int i=c; i<n; i++)
            a[i] = a[i-c];

        d[0] = a[0];
        for (int i=1; i<n; i++)
            d[i] = d[i-1] + a[i];

        int i;
        for (i=0; i<n && d[i] * 2 < t; i++);

        a[i] = d[i] - t/2;
        sort(a+i, a+n);

        long long ans = d[n-1] * 2;

        for (int j=n-1; j>=i && j >= n-s; j--)
            ans -= a[j];

        cout << ans << endl;
    }
    
    return 0;
}
