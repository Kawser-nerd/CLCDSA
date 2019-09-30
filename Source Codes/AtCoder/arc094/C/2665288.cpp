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
vector<ll> A, B;
int main()
{
    cin >> N;
    A.resize(N);
    B.resize(N);
    ll res = LL_INF;
    ll sum = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i] >> B[i];
        sum += A[i];
        if (A[i] > B[i])
        {

            res = min(res, B[i]);
        }
    }
    if (A == B)
    {
        cout << 0 << endl;
        return 0;
    }
    cout << sum - res << endl;

    return 0;
}