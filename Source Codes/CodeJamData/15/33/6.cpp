#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int tt=1; tt <= t; tt++)
    {
        int c, n, s;
        int a[128];

        cin >> c >> n >> s;

        for (int i = 0; i < n; i++)
            cin >> a[i];
        a[n] = s + 1;

        int k = 0;

        for (long long x = 1, i = 0; x <= s; )
            if (x >= a[i])
            {
//                cout << a[i] << " " << x << endl;
                x += (long long)c * a[i];
                i++;
            }
            else
            {
//                cout << x << endl;
                x *= c + 1;
                k++;
            }

        cout << "Case #" << tt << ": " << k << endl;
    }

    return 0;
}
