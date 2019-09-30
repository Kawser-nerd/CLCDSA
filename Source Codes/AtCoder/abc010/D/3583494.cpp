#include <iostream>
#include <algorithm>

using namespace std;

int g[101][101];
int gg[101][101];
//int isUsed[101][101][101];
int isUsed[1000][101];
int cnt = 0;

int N, G, E;

int dfs(int v)
{
    if(v == N)
    {
        return 1;
    }
    isUsed[cnt][v] = 1;
    for (int i = N; i >= 0; i--)
    {
        if(gg[v][i] != 0 && isUsed[cnt][i] == 0)
        {
            int ret = dfs(i);
            if (ret == 1)
            {
                gg[v][i]--;
                gg[i][v]++;
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    cin >> N >> G >> E;

    for (int i = 0; i < G;i++)
    {
        int p;
        cin >> p;
        g[p][N] = 1;
        gg[p][N] = 1;
        g[N][p] = 1;
        gg[N][p] = 1;
    }

    for (int i = 0; i < E;i++)
    {
        int a, b;
        cin >> a >> b;
        g[a][b] = 1;
        g[b][a] = 1;
        gg[a][b] = 1;
        gg[b][a] = 1;
    }

    while(dfs(0) && cnt <=100)
    {
        cnt++;
    }
    int num = 0;
    for (int i = 1; i <= N;i++)
    {
        if(g[0][i] == 1 && gg[0][i] == 0)
        {
            num++;
        }
    }

/*
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            cout << g[i][j];
        }
        cout << endl;
    }

    for (int i = 0; i <= N;i++)
    {
        for (int j = 0; j <= N;j++)
        {
            cout << gg[i][j];
        }
        cout << endl;
    }
*/

    cout << num << endl;

    return 0;
}