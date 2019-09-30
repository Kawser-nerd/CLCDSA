#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <iomanip>
#include <numeric>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define SORT(c) sort((c).begin(), (c).end())

typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> V;
typedef map<int, int> M;

int main()
{

    int n, m, a[112345];

    cin >> n >> m;

    REP(i, n)
    cin >> a[i];

    int one = 0;

    REP(i, n - 1)
    one += (a[i] < a[0] && a[0] < a[i + 1]) || (a[0] < a[i + 1] && a[i + 1] < a[i]) || (a[i + 1] < a[i] && a[i] < a[0]);

    int imos[112345];

    fill(imos, imos + m + 1, 0);

    REP(i, n - 1)
    {
        imos[(a[i] + 1) % m + (a[i] + 1 == m) * m]++;
        imos[a[i + 1]]--;
    }

    for (int i = 1; i <= m; i++)
        imos[i] += imos[i - 1];

    int imos1 = imos[a[0]];

    for (int i = 1; i <= m; i++)
        imos[i] += one - imos1;

    int imos_[112345];

    for (int i = 1; i <= m; i++)
        imos_[i + 1] = imos[i];

    for (int i = 1; i <= m; i++)
        imos[i] = imos_[i];

    ll res = 1e18;
    ll sum = 0;

    REP(i, n - 1)
    {
        sum += (min(1 + (a[i + 1] - 1 + m) % m, (a[i + 1] - a[i] + m) % m));
    }

    ll add[112345];
    fill(add, add + m + 1, 0);

    REP(i, n - 1)
    add[(a[i + 1] + 1) /* % m + (a[i + 1] + 1 == m) * m*/] += (a[i + 1] - a[i] + m) % m - 1;

    res = sum;

    for (int i = 2; i <= m; i++)
    {
        sum += add[i];
        sum -= imos[i];

        res = min(res, sum);
    }

    cout << res << endl;

    return 0;
}