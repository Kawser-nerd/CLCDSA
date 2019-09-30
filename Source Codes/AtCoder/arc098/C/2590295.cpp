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
int N, K, Q;
vector<int> A;
int main()
{
    cin >> N >> K >> Q;
    A.resize(N);
    for (auto &val : A)
    {
        cin >> val;
    }
    ll result = LL_INF;
    for (int i = 0; i < N; i++)
    {
        const int X = A[i];
        vector<int> candidates;
        vector<int> tmp;
        for (int j = 0; j < N; j++)
        {
            if (A[j] >= X)
            {
                tmp.push_back(A[j]);
            }
            else if (A[j] < X)
            {
                int m = tmp.size();
                sort(tmp.begin(), tmp.end());
                for (int j = 0; j < m - K + 1; j++)
                {
                    candidates.push_back(tmp[j]);
                }
                tmp.clear();
            }
        }
        int m = tmp.size();
        sort(tmp.begin(), tmp.end());
        for (int j = 0; j < m - K + 1; j++)
        {
            candidates.push_back(tmp[j]);
        }
        tmp.clear();

        sort(candidates.begin(), candidates.end());
        if (candidates.size() >= Q)
        {
            result = min(result, (ll)candidates[Q - 1] - X);
        }
    }
    cout << result << endl;
  return 0;
}