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
vector<int> A, B;
int main()
{
    cin >> N;
    A.resize(N);
    B.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> B[i];
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int result = 0;
    for (int k = 0; k < 29; k++)
    {
        const int T = 1 << k;
        vector<int> B_MOD(N);
        for (int i = 0; i < N; i++)
        {
            B_MOD[i] = B[i] % (1 << (k + 1));
        }
        sort(B_MOD.begin(), B_MOD.end());
        int cnt = 0;
        for (int i = 0; i < N; i++)
        {
            int A_MOD = A[i] % (1 << (k + 1));
            int idx1 = lower_bound(B_MOD.begin(), B_MOD.end(), T - A_MOD) - B_MOD.begin();
            int idx2 = lower_bound(B_MOD.begin(), B_MOD.end(), 2 * T - A_MOD) - B_MOD.begin();
            cnt += idx2 - idx1;
            int idx3 = lower_bound(B_MOD.begin(), B_MOD.end(), 3 * T - A_MOD) - B_MOD.begin();
            int idx4 = lower_bound(B_MOD.begin(), B_MOD.end(), 4 * T - A_MOD) - B_MOD.begin();
            cnt += idx4 - idx3;
        }
        if (cnt % 2)
        {
            result += 1 << k;
        }
    }
    cout << result << endl;

    return 0;
}