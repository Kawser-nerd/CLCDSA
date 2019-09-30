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

int N, M, Q;

int main()
{
    cin >> N >> M;
    vector<vector<int> > g(N);
    vector<int> vd(N, -1);
    vector<int> col(N, 0);

    for (int i = 0; i < M;i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    cin >> Q;
    vector<int> v(Q), d(Q), c(Q);
    for (int i = 0; i < Q;i++)
    {
        cin >> v[i] >> d[i] >> c[i];
        v[i]--;
    }
    queue<int> que;
    for (int i = Q - 1; i >= 0; i--)
    {
        auto push = [&](int vv, int dd)
        {
            if(vd[vv] < dd)
            {
                vd[vv] = dd;
                if (col[vv] == 0)
                {
                    col[vv] = c[i];
                }
                que.push(vv);
            }
        };
        push(v[i], d[i]);
        while(que.size())
        {
            int vv = que.front();
            que.pop();
            if(vd[vv] == 0)
            {
                continue;
            }
            for (int j = 0; j < g[vv].size(); j++)
            {
                push(g[vv][j], vd[vv]-1);
            }
        }
    }

    for (int i = 0; i < N;i++)
    {
        cout << col[i] << endl;
    }
    return 0;
}