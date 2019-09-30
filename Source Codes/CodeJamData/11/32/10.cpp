#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define PI 3.1415926535897932384626433832795

const int size = 1000 * 10;
long long a[size];
vector <long long> dist;

int main()
{
    int tc, n, l, c, i, j, p, tn;
    long long t, d, tm, ans;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> tc;
    for (tn = 0; tn < tc; tn++)
    {
        cin >> l >> t >> n >> c;
        for (i = 0; i < c; i++)
        {
            cin >> a[i];
            a[i] *= 2;
        }
        dist.clear();
        for (i = 0; i < n; i++)
            dist.pb(a[i % c]);
        tm = t;
        p = 0;
        while (p < n && tm > 0)
        {
            d = min(dist[p], tm);
            dist[p] -= d;
            tm -= d;
            if (dist[p] == 0)
                p++;
        }
        sort(dist.rbegin(), dist.rend());
        ans = (t - tm) * 2;
        for (i = 0; i < l; i++)
            ans += dist[i];
        for (i = l; i < n; i++)
            ans += dist[i] * 2;
        cout << "Case #" << tn + 1 << ": " << ans / 2 << endl;
    }
    return 0;
}
