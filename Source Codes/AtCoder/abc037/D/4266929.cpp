#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

const long long mod = 1e9 + 7;
long long H, W;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
long long graph[1001][1001];
long long memo[1001][1001];

long long dfs(int x, int y)
{
    if (memo[x][y] != -1)
    {
        return memo[x][y];
    }
    long long sum = 1;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx > W || ny < 0 || ny > W)
        {
            continue;
        }
        if (graph[x][y] >= graph[nx][ny])
        {
            continue;
        }
        sum += dfs(nx, ny);
        sum %= mod;
    }
    return (memo[x][y] = sum);
}

int main()
{
    cin >> H >> W;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            memo[i][j] = -1;
            cin >> graph[i][j];
        }
    }

    long long ans = 0;

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            ans += dfs(i, j);
            ans %= mod;
        }
    }

    cout << ans << endl;

    return 0;
}