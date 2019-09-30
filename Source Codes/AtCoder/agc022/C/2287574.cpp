#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <vector>
#define REP(i, n) for (int i = 0; (i) < int(n); ++ (i))
#define REP3R(i, m, n) for (int i = int(n) - 1; (i) >= int(m); -- (i))
#define ALL(x) begin(x), end(x)
using ll = long long;
using namespace std;
template <class T> inline void chmin(T & a, T const & b) { a = min(a, b); }

constexpr int inf = 1e9 + 7;
constexpr int max_a = 50;
ll solve(int n, vector<int> const & a, vector<int> const & b) {
    // compute the costs
    array<array<int, max_a + 1>, max_a + 1> max_k = {};
    REP (i, max_a + 1) {
        REP (j, max_a + 1) {
            max_k[i][j] = inf;
        }
        max_k[i][i] = 0;
    }
    REP3R (kk, 1, max_a + 1) {
        REP (i, max_a + 1) {
            int j = i % kk;
            chmin(max_k[i][j], kk);
        }
        REP (k, max_a + 1) {
            REP (i, max_a + 1) if (max_k[i][k] != inf) {
                REP (j, max_a + 1) if (max_k[k][j] != inf) {
                    chmin(max_k[i][j], max(max_k[i][k], max_k[k][j]));
                }
            }
        }
    }
    // check trivial cases
    if (a == b) {
        return 0;
    }
    REP (i, n) {
        if (max_k[a[i]][b[i]] == inf) {
            return -1;
        }
    }
    // reconstruct
    ll answer = 0;
    vector<vector<int> > aa(n);
    REP (i, n) aa[i].push_back(a[i]);
    while (true) {
        vector<int> min_k(n, inf);
        REP (i, n) {
            REP (j, aa[i].size()) {
                chmin(min_k[i], max_k[aa[i][j]][b[i]]);
            }
        }
        int k = *max_element(ALL(min_k));
        assert (k != inf);
        if (k == 0) break;
        answer |= 1ll << k;
        REP (i, n) {
            vector<int> next_aa_i;
            REP (j, aa[i].size()) {
                for (int na : { aa[i][j], aa[i][j] % k }) {
                    if (max_k[na][b[i]] < k) {
                        next_aa_i.push_back(na);
                    }
                }
            }
            aa[i] = next_aa_i;
            sort(ALL(aa[i]));
            aa[i].erase(unique(ALL(aa[i])), aa[i].end());
        }
    }
    return answer;
}

int main() {
    int n; cin >> n;
    vector<int> a(n); REP (i, n) cin >> a[i];
    vector<int> b(n); REP (i, n) cin >> b[i];
    ll answer = solve(n, a, b);
    cout << answer << endl;
    return 0;
}