#include <iostream>
#include <sstream>
#include <string>
#include <cassert>
#include <cmath>
#include <climits>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <functional>
#include <numeric>
#include <iomanip>

using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

#define REP(i,n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i,a,b) for(int i = (a); i < (int)(b); ++i)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(v) ((int)v.size())

#define pb push_back
#define mp make_pair
#define mt make_tuple

int N, M;
int score = 1e9;

int calc_score(vector<int>& idx, vector<vector<int>>& As) {
    map<int, int> m;
    int ret = 0;
    REP(n,N) {
        ++m[As[n][idx[n]]];
        // cout << As[n][idx[n]] << ",";
        ret = max(ret, m[As[n][idx[n]]]);
    }
    // cout << endl;
    // cout << "score:" << ret << endl;
    return ret;
}

set<set<int>> taken_seen;
void dfs(vector<int>& idx, vector<vector<int>>& As, set<int>& taken) {

    auto local_score = calc_score(idx, As);
    score = min(score, local_score);

    if (SIZE(taken) == M-1) {
        return;
    }

    auto M_rem = M - SIZE(taken);
    auto best_score = (N + (M_rem - 1)) / M_rem;
    // cout << "cur_score, best_score::" << score << "," << best_score << endl;
    if (best_score >= score) return;

    map<int, vector<int>> m;
    REP(n,N) {
        m[As[n][idx[n]]].pb(n);
    }

    int largest_m = 0;
    for(auto p: m) {
        largest_m = max(largest_m, SIZE(p.second));
    }
    if(largest_m == 1) return;

    for(auto p: m) {
        if (SIZE(p.second) == largest_m) {
            auto idx2 = idx;
            auto taken2 = taken;
            taken2.insert(p.first);

            if (taken_seen.count(taken2)) continue;
            taken_seen.insert(taken2);

            // cout << "taken: ";
            // for(auto zz: taken) cout << zz << " ";
            // cout << ". now " << p.first << " is taken" << endl;

            for(auto person: p.second) {
                while(taken2.count(As[person][idx2[person]])) {
                    ++idx2[person];
                }
            }
            dfs(idx2, As, taken2);
            break;
        }
    }
}

int main(void)
{
    cin.sync_with_stdio(false);
    cin >> N >> M;
    vector<vector<int>> As(N, vector<int>(M));
    REP(n,N) REP(m,M) cin >> As[n][m];


    vector<int> idx(N);
    set<int> taken;
    dfs(idx, As, taken);

    cout << score << endl;

    return 0;
}