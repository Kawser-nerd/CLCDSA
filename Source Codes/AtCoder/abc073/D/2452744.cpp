#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <vector>
#include <cmath>
#include <numeric>

using namespace std;

const int INF = 100100100;

typedef pair<int, int> pii;

typedef struct edge{
    int to;
    int cost;
}edge;

int N, M, R;
int r[8];
int ans = INF;
vector<vector<edge> > m;
int d[201][201];
int used[201];

void dijkstra(int s)
{

    d[s][s] = 0;

    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push(make_pair(0, s));

    while(!pq.empty())
    {
        pii p = pq.top();
        pq.pop();

        int from = p.second;

        if(d[s][from] < p.first)
        {
            continue;
        }
        
        for (int i = 0; i < m[from].size(); i++)
        {
            int to = m[from][i].to;
            int c = m[from][i].cost;
            //cout << "to  = " << to << endl;
            if (d[s][to] > d[s][from] + c)
            {
                d[s][to] = d[s][from] + c;
                pq.push(make_pair(d[s][to], to));
            }
        }
    }
}

void dfs(int p, int c, int n)
{
    if (n == R)
    {
        ans = min(ans, c);
        return;
    }
    used[p] = 1;

    for (int i = 0; i < R;i++)
    {
        int to = r[i];
        if (used[to] == 1)
        {
            continue;
        }
        dfs(to, c + d[p][to], n + 1);
    }
    used[p] = 0;
}

int main()
{
    cin >> N >> M >> R;

    m.resize(N + 1);


    for (int i = 0; i < 201;i++)
    {
        for (int j = 0; j < 201;j++)
        {
            d[i][j] = INF;
        }
    }

    for (int i = 0; i < R; i++)
    {
        cin >> r[i];
    }
    for (int i = 0; i < M;i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge t;
        t.to = a;
        t.cost = c;
        m[b].push_back(t);
        t.to = b;
        m[a].push_back(t);
    }

    for (int i = 0; i < R;i++)
    {
        dijkstra(r[i]);
    }

/*
    for (int i = 0; i < R;i++)
    {
        for (int j = 1; j <= N;j++)
        {
            cout << r[i] << " -> " << j << " : " << d[r[i]][j] << endl;
        }
    }
*/
        for (int i = 0; i < R; i++)
        {
            dfs(r[i], 0, 1);
        }

    

    cout << ans << endl;

    return 0;
}