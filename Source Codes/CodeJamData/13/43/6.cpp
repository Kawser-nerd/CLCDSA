#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int maxn = 2000 + 5;

int n, a[maxn], b[maxn], d[maxn], bb[maxn], ans[maxn];
vector<int> e[maxn];

void add(int s, int t)
{
    e[s].push_back(t);
    ++d[t];
}

void work()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        a[i] = b[i] = d[i] = 0;
        e[i].clear();
    }
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        if (a[x] != 0)
            add(i, a[x]);
        if (a[x - 1] != 0)
            add(a[x - 1], i);
        a[x] = i;
    }
    for (int i = 1; i <= n; ++i)
        cin >> bb[i];
    for (int i = n; i >= 1; --i) {
        int x = bb[i];
        if (b[x] != 0)
            add(i, b[x]);
        if (b[x - 1] != 0)
            add(b[x - 1], i);
        b[x] = i;
    }
    set<int> q;
    for (int i = 1; i <= n; ++i)
        if (d[i] == 0)
            q.insert(i);
    for (int i = 1; i <= n; ++i) {
        int x = *q.begin();
        q.erase(q.begin());
        ans[x] = i;
        for (int j = 0; j < e[x].size(); ++j) {
            int k = e[x][j];
            if ((--d[k]) == 0)
                q.insert(k);
        }
    }
    for (int i = 1; i <= n; ++i)
        cout << " " << ans[i];
}

int main()
{
    freopen("c2.in", "r", stdin);
    freopen("c2.out", "w", stdout);

    int t2;
    cin >> t2;
    for (int t1 = 1; t1 <= t2; ++t1) {
        printf("Case #%d:", t1);
        work();
        printf("\n");
    }
    
    return 0;
}
