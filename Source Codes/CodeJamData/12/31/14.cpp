// vim:set ts=8 sw=4 et smarttab:
// Round 1C 2012

#include <cstdio>
#include <cstring>
#include <cassert>
#include <vector>

int n;
std::vector<std::vector<int> > adj;
std::vector<bool> visit;

bool dfs(int v)
{
    if (visit[v])
    {
        return true;
    }
    visit[v] = true;
    for (std::vector<int>::const_iterator it = adj[v].begin(); it != adj[v].end(); ++it)
    {
        if (dfs(*it))
        {
            return true;
        }
    }
    return false;
}

bool solve()
{
    for (int i = 0; i < n; ++i)
    {
        visit.clear();
        visit.resize(n, false);
        if (dfs(i))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int ntc;
    scanf("%d", &ntc);
    for (int tc = 1; tc <= ntc; ++tc)
    {
        scanf("%d", &n);
        adj.clear();
        adj.resize(n);
        for (int i = 0; i < n; ++i)
        {
            int t;
            scanf("%d", &t);
            for (int j = 0; j < t; ++j)
            {
                int t2;
                scanf("%d", &t2);
                --t2;
                adj[i].push_back(t2);
            }
        }
        bool ans = solve();
        if (ans)
        {
            printf("Case #%d: Yes\n", tc);
        }
        else
        {
            printf("Case #%d: No\n", tc);
        }
    }
}
