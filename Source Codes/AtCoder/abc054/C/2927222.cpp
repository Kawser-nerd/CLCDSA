#include <cstdio>

using namespace std;

const int nmax = 8;
bool graph[nmax][nmax];
int n;


int dfs(int v, bool visited[nmax])
{
    bool all_visited = true;

    for (int i = 0; i < n; i++) {
        if (visited[i] == false)
            all_visited = false;
    }

    if (all_visited)
        return 1;

    int ret = 0;

    for (int i = 0; i < n; i++) {
        if (graph[v][i] == false)
            continue;
        if (visited[i])
            continue;
        
        visited[i] = true;
        ret += dfs(i, visited);
        visited[i] = false;
    }   

    return ret;
}

int main(void)
{
    int m;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++) {
        int A, B;
        scanf("%d%d", &A, &B);
        graph[A-1][B-1] = graph[B-1][A-1] = true;
    }

    bool visited[nmax];
    for (int i = 0; i < n; i++)
        visited[i] = false;

    visited[0] = true;
    printf("%d\n", dfs(0, visited));
    return 0;
}