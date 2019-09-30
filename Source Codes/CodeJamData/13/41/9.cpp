#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

typedef long long LL;
const LL MOD = 1000002013;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<int> o(M), e(M), p(M);
    set<int> ev;
    LL prev = 0;
    for (int i = 0; i < M; ++i) {
        cin >> o[i] >> e[i] >> p[i];
        ev.insert(o[i]);
        ev.insert(e[i]);
        LL k = e[i] - o[i];
        LL c = (2LL * N + 1 - k) * k / 2;
        c %= MOD;
        prev = (prev + p[i] * c) % MOD;
    }

    vector<int> ex(ev.begin(), ev.end());
    int last = 0;
    map<int, LL> pas;
    LL cost = 0;
    for (int i = 0; i < ex.size(); ++i) {
        for (int j = 0; j < M; ++j) if (o[j] == ex[i]) pas[o[j]] += p[j];
        LL out = 0;
        for (int j = 0; j < M; ++j) if (e[j] == ex[i]) {
            out += p[j];
        }
        while (out > 0) {
            LL in = pas.rbegin()->second;
            LL fr = pas.rbegin()->first;
            pas.erase(--pas.end());

            LL k = ex[i] - fr;
            LL c = (2LL * N + 1 - k) * k / 2;
            c %= MOD;

            LL w = min(in, out);
            in -= w;
            out -= w;
            cost = (cost + w % MOD * c % MOD) % MOD;

            if (in > 0) {
                pas[fr] = in;
            }
        }
    }

    static int testid;
    cout << "Case #" << ++testid << ": " << (prev - cost % MOD + MOD) % MOD << endl;
}

int main() {
    int tests;
    cin >> tests;
    while (tests --> 0)
        solve();
    return 0;
}
