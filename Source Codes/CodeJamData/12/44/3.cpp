#include <iostream>
#include <cstdio>
#include <vector>
#include <cassert>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

typedef unsigned long long ull;

int count_bit(ull x) {
    int res = 0;
    while (x) {
        res += x & 1;
        x >>= 1;
    }
    return res;
}

ull reach(const vector<string>& f, int x, int y, ull msk) {
    if (f[x][y] == '#') return msk;
    int id = (x - 1) * (f[0].size() - 2) + y - 1;
    if (msk & (1LL << id)) return msk;

    msk |= 1LL << id;

    msk |= reach(f, x - 1, y, msk);
    msk |= reach(f, x, y - 1, msk);
    msk |= reach(f, x, y + 1, msk);

    return msk;
}

bool is_lucky(const vector<string>& f, ull ori, ull msk, set<ull>& used) {
    if (used.count(msk)) return false;
    if (count_bit(msk) == 1) 
        return true;
    used.insert(msk);

    int dx[] = {+1, 0, 0};
    int dy[] = {0, -1, 1};

    bool result = false;
    for (int it = 0; it < 3; it++) {
        int n = f.size() - 2;
        int m = f[0].length() - 2;
        
        ull newMsk = 0;

        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
            int id = i * m + j;
            if (msk & (1LL << id)) {
                int ii = i + dx[it];
                int jj = j + dy[it];
                if (f[ii + 1][jj + 1] == '#') {
                    ii = i; jj = j;
                }
                int ID = ii * m + jj;
                newMsk |= 1LL << ID;
            }
        }

        if ((ori | newMsk) != ori) continue;
        result |= is_lucky(f, ori, newMsk, used);
    }

    return result;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> f(n);
    for (int i = 0; i < n; i++)
        cin >> f[i];

    static int test;
    cout << "Case #" << ++test << ":\n";
    for (int d = 0; d < 10; d++) for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (f[i][j] == '0' + d) {
        ull msk = reach(f, i, j, 0);
        set<ull> used;
        string lucky = is_lucky(f, msk, msk, used) ? "Lucky" : "Unlucky";
        cout << d << ": " << count_bit(msk) << ' ' << lucky << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
