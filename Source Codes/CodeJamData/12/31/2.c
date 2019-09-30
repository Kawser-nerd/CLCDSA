#include <stdio.h>

#define MAXN 1100
#define MAXM 10010
#define true 1
#define false 0


int nodeV[MAXM], nextE[MAXM], n, cnt, indE[MAXN], counter[MAXN];
int visited[MAXN];

void addEdge(int u, int v)
{
    cnt++;
    nodeV[cnt] = v, nextE[cnt] = indE[u];
    indE[u] = cnt;
}

int find(int u)
{
    visited[u] = true;
    counter[u]++;
    if (counter[u] == 2)
        return true;
    int edge  = indE[u];
    while (edge > 0)
    {
        int v = nodeV[edge];
        if (find(v))
            return true;
        edge = nextE[edge];
    }
    return false;
}

int main()
{
    int testc, test, i, j;
    
    FILE *fin = fopen("gcj3_1.in", "r");
    FILE *fout = fopen("gcj3_1.out", "w");
    
    fscanf(fin, "%d", &testc);
    for (test = 1; test <= testc; test++)
    {
        fscanf(fin, "%d", &n);
        cnt = 0;
        for (i = 1; i <= n; i++)
        {
            indE[i] = -1;
            int m;
            fscanf(fin, "%d", &m);
            for (j = 1; j <= m; j++)
            {
                int v;
                fscanf(fin, "%d", &v);
                addEdge(i, v);
            }
            visited[i] = false;
        }
        int diamond = false;
        for (i = 1; !diamond && i <= n; i++)
            if (!visited[i])
            {
                for (j = 1; j <= n; j++)
                    counter[j] = 0;
                if (find(i))
                    diamond = true;
            }
        if (diamond)
            fprintf(fout, "Case #%d: Yes\n", test);
        else
            fprintf(fout, "Case #%d: No\n", test);
    }
    
    fclose(fin);
    fclose(fout);
    
    return 0;
}

