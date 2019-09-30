#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<ll> x(n), y(n);
    vector<ll> xary, yary;

    for (int i = 0; i < n;i++)
    {
        cin >> x[i] >> y[i];

        xary.push_back(x[i]);
        yary.push_back(y[i]);
    }

    sort(xary.begin(), xary.end());
    sort(yary.begin(), yary.end());

    ll ans = 1LL * (xary[n - 1] - xary[0]) * (yary[n - 1] - yary[0]);

    for (int xi = 0; xi < n;xi++)
    {
        for (int xj = xi + 1; xj < n;xj++)
        {
            for (int yi = 0; yi < n;yi++)
            {
                for (int yj = yi + 1; yj < n;yj++)
                {
                    ll l = xary[xi];
                    ll r = xary[xj];
                    ll d = yary[yi];
                    ll u = yary[yj];

                    // check the number of points in the rectangle.
                    int cnt = 0;
                    for (int i = 0; i < n; i++)
                    {
                        if(l <= x[i] && x[i] <= r && d <= y[i] && y[i] <= u)
                        {
                            cnt++;
                        }
                    }

                    if(cnt >= k)
                    {
                        ans = min(ans, 1LL * (r - l) * (u - d));
                    }
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}