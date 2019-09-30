#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <tuple>
#include <stack>

using namespace std;

#ifdef ZTDebug
#define In scanf_s
#else
#define In scanf
#endif // ZTDebug

#define Ind(d) In("%d", &d)
#define Ind2(a, b) In("%d%d", &a, &b)
#define InD(d) int d; In("%d", &d);
#define InD2(a, b) int a, b; In("%d%d", &a, &b);
#define InDN(n, v) for (auto _i = 0; _i < n; ++_i) In("%d", &v[_i]);
#define OutDNLine(n, v) for (auto _i = 0; _i < n; ++_i) printf("%d%c", *(v + _i), _i + 1 == n ? '\n' : ' ');

typedef double db;
typedef long long LL;
typedef pair<int, int> pii;

const int Max = 100010;

vector<int> edges[Max];
int res[Max];

int dfs(int x, int f) {
    auto r = 0;
    for (auto y : edges[x]) if (y != f) r ^= dfs(y, x) + 1;
    return r;
}

int main() {
#ifdef ZTDebug
    while (true) {
        for (auto i = 0; i < Max; ++i) edges[i].clear();
#endif // ZTDebug
        int n;
        cin >> n;
        for (auto i = 1; i < n; ++i) {
            InD2(x, y);
            edges[x].push_back(y);
            edges[y].push_back(x);
        }
        cout << (dfs(1, -1) > 0 ? "Alice" : "Bob") << endl;
#ifdef ZTDebug
    }
#endif // ZTDebug
    return 0;
}