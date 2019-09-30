#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>

using namespace std;

typedef unsigned uint;
typedef long long Int;

const int INF = 1001001001;
const Int INFLL = 1001001001001001001LL;

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> void chmin(T& a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T& a, T b) { if (a < b) a = b; }

int N;
Int E, R, V[10050];

Int solve_small()
{
    Int dp[110][110] = {{}};
    dp[0][E] = 0;

    for (int i = 0; i < N; ++i) {
        for (int e = 0; e <= E; ++e) {
            for (int f = 0; f <= e; ++f) {
                chmax(dp[i + 1][min(e - f + R, E)], dp[i][e] + f * V[i]);
            }
        }
    }

    return dp[N][min(E, R)];
}

pair<Int, int> P[10050];
Int SE[10050], EE[10050];

Int solve_large()
{
    for (int i = 0; i < N; ++i) {
        P[i] = make_pair(V[i], i);
    }
    sort(P, P + N);
    reverse(P, P + N);

    set<int> determined;
    for (int i = 0; i < N; ++i) {
        int v = P[i].second;
        Int start = E, end = 0;
        set<int>::iterator bef, aft;
        
        bef = determined.lower_bound(v);
        if (bef != determined.begin()) {
            int w = *--bef;
            chmin(start, EE[w] + (Int)R * (v - w));
        }

        aft = determined.upper_bound(v);
        if (aft != determined.end()) {
            int w = *aft;
            chmax(end, SE[w] - (Int)R * (w - v));
        }

        SE[v] = start;
        EE[v] = end;
        determined.insert(v);
        assert(start >= end);
    }

    Int res = 0;
    for (int i = 0; i < N; ++i) {
        res += (SE[i] - EE[i]) * V[i];
    }

    return res;
}

int main()
{
    int T;
    cin >> T;

    for (int CN = 1; CN <= T; ++CN) {
        cin >> E >> R >> N;
        for (int i = 0; i < N; ++i) {
            cin >> V[i];
        }

        Int res = solve_large();

        cout << "Case #" << CN << ": " << res << endl;
    }

    return 0;
}
