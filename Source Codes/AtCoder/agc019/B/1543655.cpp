/*
 * Created by KeigoOgawa
 */


#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <cassert>
#include <cmath>

#define INF (int)1e8
#define EPS 1e-10
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define RFOR(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define RREP(i, n) for (int i = (n) - 1; i >= 0; i--)
#define MIN(a, b) (a > b ? b : a)
#define MAX(a, b) (a > b ? a : b)
#define debug(x) cout << #x << ": " << x << endl
#define all(a) (a).begin(), (a).end()

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;

string a;
ll ans = 0;

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> a;
    ll count[27] = {0};
    ans = (ll)a.size() * (ll)(a.size() - 1) / 2;

    REP(i, a.size()) {
        count[a[i] - 'a']++;
    }
    REP(i, 27) {
        ll c = count[i] - 1;
        if (c <= 0) continue;
        ans -= c * (c+1) / 2;
    }
    ans++;
    cout << ans << endl;
    return 0;
}