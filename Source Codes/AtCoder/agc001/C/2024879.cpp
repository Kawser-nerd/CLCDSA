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
int N, K;
const int MAX_N = 2010;
vector<int> edges[MAX_N];
int M;
int res;
void dfs(int pos, int pre, int len)
{
    // cerr << pos << " "<< pre << " " << len << endl;
    if (len > M)
    {
        res++;
    }

    for (auto &val : edges[pos])
    {
        if (val == pre)
        {
            continue;
        }
        dfs(val, pos, len + 1);
    }
}
int main()
{
    cin >> N >> K;
    M = K / 2;
    rep(i, N - 1)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    int result = INF;
    for (int i = 0; i < N; i++)
    {
        if (K % 2 == 0)
        {
            res = 0;
            dfs(i, -1, 0);
            result = min(result, res);
        }
        else
        {
            for (int p : edges[i])
            {
                
                int res1,res2;
                
                res = 0;
                dfs(i, p, 0);
                res1 = res;

                res = 0;
                dfs(p, i, 0);
                res2 = res;
                result = min(result, res1 + res2);
            }
            
        }
        // cerr << "i = " << i << " res = " << res << endl;
    }
    cout << result << endl;
    return 0;
}