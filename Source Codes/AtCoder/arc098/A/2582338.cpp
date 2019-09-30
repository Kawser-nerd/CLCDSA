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
int N;
string S;
const int MAX_N = 300010;
int west[MAX_N];
int east[MAX_N];
int main()
{
    cin >> N;
    cin >> S;
    for (int i = 0; i < N; i++)
    {
        if (S[i] == 'W')
        {
            west[i + 1]++;
        }
        else
        {
            east[i + 1]++;
        }
        west[i + 1] += west[i];
        east[i + 1] += east[i];
    }
    int res = INF;
    for (int i = 1; i <= N; i++)
    {
        int west1 = west[i - 1];
        int east1 = east[N] - east[i];
        res = min(res, west1 + east1);
    }
    cout << res << endl;

    return 0;
}