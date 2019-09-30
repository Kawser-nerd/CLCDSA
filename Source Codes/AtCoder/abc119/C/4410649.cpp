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
template <class T>
using max_priority_queue = priority_queue<T>;
template <class T>
using min_priority_queue = priority_queue<T, std::vector<T>, std::greater<T>>;

const int INF = 1 << 29;
const ll LL_INF = 1LL << 60;
const double EPS = 1e-9;
const ll MOD = 1000000007;

const int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};
int N, A, B, C;
vector<ll> L;
ll calc(vector<ll> groups, ll cost)
{
    if (groups.size() < 3)
    {
        return LL_INF;
    }
    ll result = LL_INF;
    sort(groups.begin(), groups.end());
    for (int i = 0; i < groups.size(); i++)
    {
        ll med = abs(groups[i] - B);
        ll left = INF;
        ll right = INF;
        for (int l = 0; l < i; l++)
        {
            left = min(left, abs(groups[l] - C));
        }
        for (int r = i + 1; r < groups.size(); r++)
        {
            right = min(right, abs(groups[r] - A));
        }
        result = min(result, cost + med + left + right);
    }
    return result;
}
ll ans = LL_INF;
void dfs(int pos, vector<ll> &groups, ll cost)
{
    if (pos >= N)
    {
        ans = min(ans, calc(groups, cost));
        return;
    }
    //not merge
    groups.push_back(L[pos]);
    dfs(pos + 1, groups, cost);
    groups.pop_back();
    //merge
    for (int i = 0; i < groups.size(); i++)
    {
        groups[i] += L[pos];
        dfs(pos + 1, groups, cost + 10LL);
        groups[i] -= L[pos];
    }
    return;
}
int main()
{
    cin >> N >> A >> B >> C;
    L.resize(N);
    for (auto &val : L)
    {
        cin >> val;
    }
    sort(L.begin(), L.end());
    vector<ll> groups;
    dfs(0, groups, 0);
    cout << ans << endl;
    return 0;
}