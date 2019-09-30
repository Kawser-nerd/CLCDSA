#include <iostream>

using namespace std;
using ll = long long;

const ll INF = 1LL << 50;

int a[2000];
int b[2000];
ll c[2000];

int main()
{
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M;i++)
    {
        cin >> a[i] >> b[i] >> c[i];
        a[i]--;
        b[i]--;
        c[i] = -c[i];
    }

    ll dist[1000];

    for (int i = 0; i < N;i++)
    {
        dist[i] = INF;
    }

    dist[0] = 0;

    for (int i = 0; i < N - 1;i++)
    {
        for (int j = 0; j < M;j++)
        {
            int u = a[j];
            int v = b[j];
            if (dist[u] == INF)
            {
                continue;
            }
            if(dist[v] > dist[u] + c[j])
            {
                dist[v] = dist[u] + c[j];
            }
        }
    }

    ll ans = dist[N - 1];

    bool negative[1000];

    for (int i = 0; i < N;i++)
    {
        negative[i] = false;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int u = a[j];
            int v = b[j];
            if (dist[u] == INF)
            {
                continue;
            }
            if (dist[v] > dist[u] + c[j])
            {
                dist[v] = dist[u] + c[j];
                negative[v] = true;
            }
            if(negative[u] == true)
            {
                negative[v] = true;
            }
        }
    }

    if(negative[N - 1] == true)
    {
        cout << "inf" << endl;
    }
    else
    {
        cout << -ans << endl;
    }

    return 0;
}