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
template <class T>
class BIT
{
  public:
    BIT() {}
    BIT(int N) : N(N) { dat.assign(N, 0); }
    // sum [0,i)
    T sum(int i)
    {
        T ret = 0;
        for (--i; i >= 0; i = (i & (i + 1)) - 1)
            ret += dat[i];
        return ret;
    }
    // sum [i,j)
    T sum(int i, int j) { return sum(j) - sum(i); }
    // add x to i
    void add(int i, T x)
    {
        for (; i < N; i |= i + 1)
            dat[i] += x;
    }
    int size() { return N; }

  private:
    int N;
    vector<T> dat;
};

int N;
const int MAX_N = 2010;
int dp[MAX_N][MAX_N];
int cost_b[MAX_N][MAX_N];
int cost_w[MAX_N][MAX_N];

void init()
{
    memset(dp, -1, sizeof(dp));
}

vector<pair<char, int>> C;
map<int, int> indices_b, indices_w;
int memo(int pos_w, int pos_b)
{
    // cerr << pos_w << " " << pos_b << endl;
    if (pos_w + pos_b >= 2 * N)
    {
        return 0;
    }
    int &res = dp[pos_w][pos_b];
    if (res >= 0)
    {
        return res;
    }
    res = INF;
    if (pos_w < N)
    {
        res = min(res, memo(pos_w + 1, pos_b) + cost_w[pos_w][pos_b]);
    }
    if (pos_b < N)
    {
        res = min(res, memo(pos_w, pos_b + 1) + cost_b[pos_w][pos_b]);
    }
    return res;
}

int main()
{
    init();
    cin >> N;
    C.resize(2 * N);
    for (auto &val : C)
    {
        cin >> val.first >> val.second;
        // cerr << val.first << " " << val.second << endl;
    }
    
    for (int i = 0; i < 2 * N; i++)
    {
        if (C[i].first == 'W')
        {
            indices_w[C[i].second] = i + 1;
        }
        else
        {
            indices_b[C[i].second] = i + 1;
        }
    }
    //white
    for (int j = 0; j <= N; j++)
    {
        BIT<int> bit(2 * N + 1);
        for (int k = 0; k <= j; k++)
        {
            if (indices_b.count(k) > 0)
            {
                int pos = indices_b[k];
                bit.add(pos, 1);
            }
        }
        for (int i = 1; i <= N; i++)
        {
            int pos = indices_w[i];
            cost_w[i - 1][j] = pos - bit.sum(0, pos) - 1;
            // cerr << "i = " << i - 1 << " j = " << j << " pos = " << pos << " " << bit.sum(0, pos) << " " << cost_w[i - 1][j] << endl;
            // assert(cost_w[i][j] >= 0);
            bit.add(pos, 1);
        }
    }
    //black
    for (int i = 0; i <= N; i++)
    {
        BIT<int> bit(2 * N + 1);
        for (int k = 0; k <= i; k++)
        {
            if (indices_w.count(k) > 0)
            {
                int pos = indices_w[k];
                bit.add(pos, 1);
            }
        }
        for (int j = 1; j <= N; j++)
        {
            int pos = indices_b[j];
            cost_b[i][j - 1] = pos - bit.sum(0, pos) - 1;
            // cerr << "i = " << i << " j = " << j - 1 << " pos = " << pos << " " << bit.sum(0, pos) << " " << cost_w[i - 1][j] << endl;
            bit.add(pos, 1);
        }
        
    }
    cout << memo(0, 0) << endl;
    return 0;
}