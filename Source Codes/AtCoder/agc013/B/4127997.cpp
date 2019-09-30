#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <queue>
#include <set>

using namespace std;

int N, M;
vector<vector<int> > g;
int used[100001];
vector<int> ans;
vector<int> ans2;

void dfs(int v)
{
    used[v] = 1;
    ans.push_back(v);
    for (int i = 0; i < g[v].size();i++)
    {
        if(used[g[v][i]] == 0)
        {
            return dfs(g[v][i]);
        }
    }
}

int main()
{
    cin >> N >> M;
    g.resize(N);
    for (int i = 0; i < M;i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(0);
    used[0] = 0;
    dfs(0);

    for (int i = ans.size() - 1; i >= 0;i--)
    {
        if(ans[i] != 0)
        {
            ans2.push_back(ans[i]);
        }
        else
        {
            ans2.push_back(ans[i]);
            break;
        }
    }
    for (int i = 1; i < ans.size(); i++)
    {
        if (ans[i] != 0)
        {
            ans2.push_back(ans[i]);
        }
        else
        {
            break;
        }
    }

    cout << ans2.size() << endl;
    for (int i = 0; i < ans2.size() - 1; i++)
    {
        cout << ans2[i] + 1 << " ";
    }
    cout << ans2[ans2.size() - 1] + 1 << endl;

    return 0;
}