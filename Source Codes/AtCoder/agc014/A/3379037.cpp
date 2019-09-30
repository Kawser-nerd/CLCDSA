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

constexpr int INF = 1e7;
constexpr ll MOD = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;

    int n = 0;

    while (true)
    {
        if (n == INF)
        {
            cout << -1 << endl;
            return 0;
        }

        if (a % 2 == 1 || b % 2 == 1 || c % 2 == 1)
            break;

        int a_ = a, b_ = b, c_ = c;

        a = (c_ + b_) / 2;
        b = (c_ + a_) / 2;
        c = (a_ + b_) / 2;

        n++;
    }

    cout << n << endl;

    return 0;
}