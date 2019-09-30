#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <iomanip>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstring>
#include <climits>

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
constexpr double PI = 3.14159265358979323846;
constexpr int di[] = {0, 0, 1, -1};
constexpr int dj[] = {1, -1, 0, 0};

int l, b[112345];

vector<int> solve(int s)
{
    V a;

    a.push_back(s);

    for (int i = 0; i < l - 1; i++)
        a.push_back(a[a.size() - 1] ^ b[i]);

    int d = b[l - 1] - (a[0] + a[a.size() - 1]);

    for (int i : a)
    {
        for (int j = 0; j < 35; j++)
        {
            if ((d & (1 << j)) && (i & (1 << j)))
            {
                a.clear();
                return a;
            }
        }
    }

    return a;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> l;
    REP(i, l)
    cin >> b[i];

    vector<int> res;

    for (int i = 0; i < 2; i++)
    {
        res = solve(i);

        if (res.size())
        {
            for (int j : res)
                cout << j << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}