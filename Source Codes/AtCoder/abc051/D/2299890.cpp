#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

#define INF 100100100

int N, M;

int g[100][100];
int cost[100][100];

set<pair<int, int> > ans;
vector<pair<int, int> > edge;

int main()
{
    cin >> N >> M;

    for (int i = 0; i < 100;i++)
    {
        for (int j = 0; j < 100;j++)
        {
            if(i == j)
            {
                g[i][j] = 0;
            }
            else
            {
                g[i][j] = INF;
            }
        }
    }

    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        g[a][b] = c;
        g[b][a] = c;
        ans.insert(make_pair(a, b));
        ans.insert(make_pair(b, a));
        edge.push_back(make_pair(a, b));
    }

    for (int i = 0; i < N;i++)
    {
        for (int j = 0; j < N;j++)
        {
            cost[i][j] = g[i][j];
        }
    }

    for (int k = 0; k < N;k++)
    {
        for (int i = 0; i < N;i++)
        {
            for (int j = 0; j < N;j++)
            {
                cost[i][j] = min(cost[i][k] + cost[k][j], cost[i][j]);
            }
        }
    }

    for (int s = 0; s < N;s++)
    {
        for (int m = 0; m < M;m++)
        {
            int i = edge[m].first;
            int j = edge[m].second;

            if ((cost[s][j] + g[j][i] == cost[s][i] || cost[s][i] + g[i][j] == cost[s][j]) && ans.find(edge[m]) != ans.end())
            {
                ans.erase(make_pair(i, j));
                ans.erase(make_pair(j, i));
            }
        }
    }

    cout << ans.size() / 2 << endl;

    return 0;
}