#include <algorithm>
#include <cctype>
#include <complex>
#include <iomanip>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

using std::string;
using std::to_string;
using std::vector;
using std::set;
using std::queue;
using std::priority_queue;

using std::min;
using std::max;
using std::sort;
using std::abs;

class edge {
   public:
    int a, b, c;
    edge() {}
    edge(int a, int b, int c) : a(a), b(b), c(c) {}
};

const int INF = 1e8;

int main() {
    int n, m;
    cin >> n >> m;

    vector<edge> es(m);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        es[i] = edge(a, b, c);
    }

    vector<vector<int>> d(n, vector<int>(n, INF));
    for (const edge& e : es) {
        d[e.a][e.b] = e.c;
        d[e.b][e.a] = e.c;
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    int cnt = 0;
    for (const edge& e : es) {
        if (d[e.a][e.b] < e.c) {
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}