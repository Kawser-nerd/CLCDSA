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
const int MAX_N = 100100;

ll solve1(vector<pii> LR)
{
    vector<int> L;
    vector<int> R;
    int N = LR.size();
    for (int i = 0; i < N; i++)
    {
        L.push_back(LR[i].first);
        R.push_back(LR[i].second);
    }
    sort(L.rbegin(), L.rend());
    sort(R.begin(), R.end());
    ll res = 0;
    int li, ri;
    li = ri = 0;
    ll pos = 0;
    while (ri < N)
    {
        cerr << L[li] << " " << R[ri] << " " << pos << endl;
        if (li == ri)
        {

            if (L[li] < pos)
            {
                break;
            }
            res += L[li] - pos;
            pos = L[li];
            li++;
        }
        else
        {
            if (R[ri] > pos)
            {
                break;
            }
            res += pos - R[ri];
            pos = R[ri];
            ri++;
        }
    }
    // cerr << li << " " << ri << endl;
    res += abs(pos);
    return res;
}

int main()
{
    int N;
    cin >> N;
    vector<pii> LR;
    LR.resize(N);

    for (int i = 0; i < N; i++)
    {
        cin >> LR[i].first >> LR[i].second;
    }
    ll res1 = 0;
    ll res2 = 0;
    res1 = solve1(LR);

    for (int i = 0; i < N; i++)
    {
        swap(LR[i].first, LR[i].second);
        LR[i].first = -LR[i].first;
        LR[i].second = -LR[i].second;
    }
    res2 = solve1(LR);
    // cout << res1 << " " << res2 << endl;
    cout << max(res1, res2) << endl;

    return 0;
}