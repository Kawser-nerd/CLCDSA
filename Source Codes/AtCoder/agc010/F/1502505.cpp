#include <cstdio>
#include <functional>
#include <vector>
#define repeat(i, n) for (int i = 0; (i) < int(n); ++(i))
using namespace std;

int main() {
    // input
    int n; scanf("%d", &n);
    vector<int> a(n); repeat (i, n) scanf("%d", &a[i]);
    vector<vector<int> > g(n);
    repeat (i, n - 1) {
        int x, y; scanf("%d%d", &x, &y); -- x; -- y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    // solve
    function<bool (int)> go = [&](int i) {
        for (int j : g[i]) if (a[i] > a[j]) {
            if (not go(j)) {
                return true;
            }
        }
        return false;
    };
    vector<int> result;
    repeat (i, n) if (a[i]) {
        if (go(i)) {
            result.push_back(i);
        }
    }
    // output
    repeat (i, result.size()) {
        printf("%d%c", result[i] + 1, i + 1 == result.size() ? '\n' : ' ');
    }
    return 0;
}