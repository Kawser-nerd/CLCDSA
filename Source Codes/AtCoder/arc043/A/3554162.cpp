#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cmath>
#include <iomanip>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <bitset>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define SORT(c) sort((c).begin(), (c).end())

typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> V;
typedef map<int, int> M;

constexpr ll INF = 1e18;
constexpr ll MOD = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, a, b, s[112345];
    double p, q;

    cin >> n >> a >> b;

    int mn = 1e9 + 10, mx = 0;
    ll sum = 0;
    REP(i, n)
    {
        cin >> s[i];
        mx = max(mx, s[i]);
        mn = min(mn, s[i]);
        sum += s[i];
    }

    if (mx == mn)
    {
        cout << -1 << endl;
        return 0;
    }

    p = 1. * b / (mx - mn);

    q = 1. * a - 1. * sum / n * p;

    cout << setprecision(10) << p << " " << q << endl;

    return 0;
}