#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cassert>
#include <memory.h>

using namespace std;

const int nn = 1 << 11;

int e[nn][nn];
int d[nn];

void solve() {
    int N;
    cin >> N;
    vector<int> a(N), b(N), x(N);
    for (int i = 0; i < N; ++i)
        cin >> a[i];
    for (int i = 0; i < N; ++i)
        cin >> b[i];

    memset(e, 0, sizeof e);
    memset(d, 0, sizeof d);

    vector<int> last(N + 1, -1);
    for (int i = 0; i < N; ++i) {
        if (last[a[i]] >= 0) {
            int fr = last[a[i]];
            ++e[fr][i];
            ++d[fr];
        }
        if (last[a[i]-1] >= 0) {
            int fr = last[a[i] - 1];
            ++e[i][fr];
            ++d[i];
        }
        last[a[i]] = i;
    }

    last.assign(N + 1, -1);
    for (int i = N - 1; i >= 0; --i) {
        if (last[b[i]] >= 0) {
            int fr = last[b[i]];
            ++e[fr][i];
            ++d[fr];
        }
        if (last[b[i]-1] >= 0) {
            int fr = last[b[i] - 1];
            ++e[i][fr];
            ++d[i];
        }
        last[b[i]] = i;
    }

    set<int> v;
    for (int i = 0; i < N; ++i) if (d[i] == 0) v.insert(i);

    int c = 1;
    while (v.size()) {
        int y = *v.begin(); v.erase(v.begin());
        assert(x[y] == 0);

        x[y] = c++;
        for (int z = 0; z < N; ++z) if (e[z][y]) {
            d[z] -= e[z][y];
            if (d[z] == 0) 
                v.insert(z);
        }
    }

    static int testid;
    cout << "Case #" << ++testid << ":";
    for (int i = 0; i < N; ++i)
        cout << ' ' << x[i];
    cout << endl;
}

int main() {
    int tests;
    cin >> tests;
    while (tests --> 0)
        solve();
    return 0;
}
