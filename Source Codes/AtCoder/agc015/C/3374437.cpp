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

    int n, m, q, s[2100][2100], apx[2100][2100], v[2100][2100], h[2100][2100];

    cin >> n >> m >> q;

    fill(apx[0], apx[n], 0);
    fill(v[0], v[n], 0);
    fill(h[0], h[n], 0);

    FOR(i, 1, n + 1)
    {
        string s_;
        cin >> s_;

        s_ = '0' + s_;

        apx[i][0] = 0;
        h[i][0] = 0;
        v[i][0] = 0;

        s[i][0] = 0;

        FOR(j, 1, m + 1)
        {
            s[0][j] = 0;

            s[i][j] = (int)(s_[j] == '1');

            apx[i][j] = apx[i][j - 1] + s[i][j];

            h[i][j] = (int)(s[i][j - 1] + s[i][j] == 2) + h[i][j - 1];

            v[i][j] = (int)(s[i - 1][j] + s[i][j] == 2) + v[i][j - 1];
        }
    }

    FOR(i, 1, n + 1)
    REP(j, m + 1)
    {
        apx[i][j] += apx[i - 1][j];
        h[i][j] += h[i - 1][j];
        v[i][j] += v[i - 1][j];

        //cout << apx[i][j] << endl;
    }

    int ans[212345];
    int a__[212345];
    int h__[212345];
    int v__[212345];

    REP(i, q)
    {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int a_ = apx[x2][y2] - apx[x1 - 1][y2] + apx[x1 - 1][y1 - 1] - apx[x2][y1 - 1];

        int h_ = h[x2][y2] - h[x1 - 1][y2] + h[x1 - 1][y1] - h[x2][y1];

        int v_ = v[x2][y2] - v[x1][y2] + v[x1][y1 - 1] - v[x2][y1 - 1];

        //cout << a_ << " " << h_ << " " << v_ << endl;

        //cout << a_ - (h_ + v_) << endl;

        ans[i] = a_ - (h_ + v_);

        a__[i] = a_;
        h__[i] = h_;
        v__[i] = v_;
    }

    REP(i, q)
    {
        //cout << a__[i] << " " << h__[i] << " " << v__[i] << endl;
        cout << ans[i] << endl;
    }

    /*
    FOR(i, 0, n + 1)
    {
        FOR(j, 0, m + 1)
        {
            cout << v[i][j] << (j == m ? "\n" : " ");
        }
    }
    */

    return 0;
}