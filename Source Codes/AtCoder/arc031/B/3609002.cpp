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
#include <cassert>

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

string s[11], s_[11];

void dfs(int i, int j)
{
    if (i > 0 && s_[i - 1][j] == 'o')
    {
        s_[i - 1][j] = 'x';
        dfs(i - 1, j);
    }
    if (i < 9 && s_[i + 1][j] == 'o')
    {
        s_[i + 1][j] = 'x';
        dfs(i + 1, j);
    }
    if (j > 0 && s_[i][j - 1] == 'o')
    {
        s_[i][j - 1] = 'x';
        dfs(i, j - 1);
    }
    if (j < 9 && s_[i][j + 1] == 'o')
    {
        s_[i][j + 1] = 'x';
        dfs(i, j + 1);
    }

    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    REP(i, 10)
    cin >> s[i];

    REP(i, 10)
    REP(j, 10)
    {
        if (s[i][j] == 'o')
            continue;

        REP(k, 10)
        REP(l, 10)
        s_[k][l] = s[k][l];

        dfs(i, j);

        bool check = true;
        REP(k, 10)
        REP(l, 10)
        if (s_[k][l] == 'o')
            check = false;

        if (check)
        {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;

    return 0;
}