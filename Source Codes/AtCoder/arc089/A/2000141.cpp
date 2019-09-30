#include <algorithm>
#include <bitset>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

// c++11
#include <array>
#include <tuple>
#include <unordered_map>
#include <unordered_set>

#define mp make_pair
#define mt make_tuple
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

const int INF = 1 << 29;
const ll LL_INF = 1LL << 60;
const double EPS = 1e-9;
const ll MOD = 1000000007;

const int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};
int N;
int main()
{
    cin >> N;
    int px, py, now;
    px = py = now = 0;
    bool ok = true;
    for (int i = 0; i < N; i++)
    {
        int t, x, y;
        cin >> t >> x >> y;
        int d = t - now;
        int res = abs(x - px) + abs(y - py);
        if (res > d)
        {
            ok = false;
        }
        d -= res;
        // cerr << t << " " << x << " " << y << endl;
        
        // cerr << d << " " << res << " " << x << " " << y << endl;
        if (d % 2 != 0)
        {
            ok = false;
        }
        px = x;
        py = y;
        now = t;
    }
    if (ok)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}