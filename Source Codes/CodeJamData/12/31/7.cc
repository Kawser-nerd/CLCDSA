#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

bool seen[1005];
vector<int> e[1005];

bool dfs(int node) {
    if (seen[node]) return true;
    seen[node] = true;

    for (int i = 0; i < e[node].size(); i++) {
        if (dfs(e[node][i])) return true;
    }
    return false;
}

int main() {

    int T, n;

    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            int m;
            scanf("%d", &m);
            e[i].clear();
            for (int j = 0; j < m; j++) {
                int a;
                scanf("%d", &a);
                e[i].push_back(a);
            }
        }
        int i;
        for (i = 1; i <= n; i++) {
            memset(seen, 0, sizeof(seen));
            if (dfs(i)) break;
        }
        printf("Case #%d: %s\n", t, (i <= n ? "Yes" : "No"));
    }

    return 0;
}



