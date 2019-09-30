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

    int n;
    cin >> n;

    if (n == 1)
    {
        cout << "Not Prime" << endl;
        return 0;
    }

    bool isP = true, isLikeP;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (!(n % i))
        {
            isP = false;
            break;
        }
    }

    if ((n % 10) % 2 == 0 || n % 10 == 5)
    {
        isLikeP = false;
    }
    else
    {
        int cnt = 0;
        while (n > 0)
        {
            cnt += n % 10;
            n /= 10;
        }

        isLikeP = cnt % 3;
    }

    cout << (isP || isLikeP ? "Prime" : "Not Prime") << endl;

    return 0;
}