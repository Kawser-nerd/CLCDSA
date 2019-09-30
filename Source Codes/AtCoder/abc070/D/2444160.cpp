#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using ll = long long;

using namespace std;

typedef struct edge {ll to, cost;}edge;
typedef pair<ll, ll> P;

ll V, N, Q, K;
vector<vector<edge> > G;
vector<ll> d;
const long long INF = 1000000000000000;

int main()
{
    cin >> N;

    G.resize(N + 1);
    d.resize(N + 1);

    for(ll i = 0;i < N - 1;i++)
    {
        ll a, b, c;

        cin >> a >> b >> c;

        edge e;
        e.to = a;
        e.cost = c; 
        G[b].push_back(e);
        e.to = b;
        G[a].push_back(e);
    }

    cin >> Q >> K;

    priority_queue<P, vector<P>, greater<P> > pq;

    pq.push(make_pair(0, K));

    fill(d.begin(), d.end(), INF);

    d[K] = 0;

    while(!pq.empty())
    {
        P p = pq.top();
        pq.pop();

        ll c = p.first;
        ll from = p.second;

        if(d[from] < c)
        {
            continue;
        }
        for(ll i = 0;i < G[from].size();i++)
        {
            edge e = G[from][i];
            if(d[e.to] > d[from] + e.cost)
            {
                d[e.to] = d[from] + e.cost;
                pq.push(make_pair(d[e.to], e.to));
            }
        }
    }
    for(ll i = 0;i < Q;i++)
    {
        ll x, y;
        cin >> x >> y;
        cout << d[x] + d[y] << endl;
    }

    return 0;
}