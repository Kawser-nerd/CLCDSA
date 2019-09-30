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
int X1, Y1, R;
int X2, Y2, X3, Y3;
bool inside_blue()
{
    for (int i = 0; i < 4; i++)
    {
        int y = Y1 + dy[i] * R;
        int x = X1 + dx[i] * R;
        if (not(X2 <= x and x <= X3 and Y2 <= y and y <= Y3))
        {
            return false;
        }
    }
    return true;
}
bool inside_circle(int y, int x)
{
    int dist = (Y1 - y) * (Y1 - y) + (X1 - x) * (X1 - x);
    if (dist <= R * R)
    {
        return true;
    }
    return false;
}
bool inside_red()
{
    bool ok = true;
    ok &= inside_circle(Y2, X2);
    ok &= inside_circle(Y2, X3);
    ok &= inside_circle(Y3, X2);
    ok &= inside_circle(Y3, X3);

    return ok;
}

int main()
{
    cin >> X1 >> Y1 >> R;
    cin >> X2 >> Y2 >> X3 >> Y3;
    if (inside_blue())
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }
    if (inside_red())
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }
    return 0;
}