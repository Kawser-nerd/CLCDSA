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
vector<int> A;
int main()
{
    cin >> N;
    A.resize(N);
    for (auto &val : A)
    {
        cin >> val;
        if (val >= N)
        {
            cout << -1 << endl;
            return 0;
        }
    }
    // impossible
    if (A[0] != 0)
    {
        cout << -1 << endl;
        return 0;
    }
    int pre = A[N - 1];
    for (int i = N - 2; i >= 0; i--)
    {
        pre--;
        if (A[i] < pre){
            cout << -1 << endl;
            return 0;
        }
        pre = max(pre, A[i]);
    }

    pre = A[0];
    ll result = 0;
    for (int i = 1; i < N; i++)
    {
        const int val = A[i];
        if (pre + 1 == val)
        {
            pre = val;
            continue;
        }
        if (pre == val)
        {

            result += pre;
            pre = val;
            continue;
        }
        if (pre > val)
        {
            result += pre;
            pre = val;
            continue;
        }
        if (pre < val)
        {
            result += pre;
            pre = val;
            continue;
        }
    }
    result += pre;
    cout << result << endl;
    return 0;
}