#include <stdio.h>
#include <string.h>

int ti, tn, n, m, i, j, k;
char a[101][101], ch, b[101][101], rela[200][200], exx[200], exy[200];
int pairx[200], pairy[200], visited[200];

int dfs(int, int);

int
dfs(int u, int rn)
{
    int v;
    for (v = 0; v < rn; ++v)
        if (rela[u][v] && !visited[v]) {
            visited[v] = 1;
            if (pairy[v] == -1 || dfs(pairy[v], rn)) {
                pairx[u] = v;
                pairy[v] = u;
                return 1;
            }
        }
    return 0;
}

int
main()
{
    fscanf(stdin, "%d", &tn);
    for (ti = 1; ti <= tn; ++ti) {
        fprintf(stdout, "Case #%d: ", ti);
        fscanf(stdin, "%d %d\n", &n, &m);
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        for (i = 0; i < m; ++i) {
            fscanf(stdin, "%c %d %d\n", &ch, &j, &k);
            if (ch == '+')
                b[j - 1][k - 1] = a[j - 1][k - 1] = 2;
            else if (ch == 'x')
                b[j - 1][k - 1] = a[j - 1][k - 1] = 1;
            else
                b[j - 1][k - 1] = a[j - 1][k - 1] = 3;
        }

        memset(rela, 0, sizeof(rela));
        memset(exx, 0, sizeof(exx));
        memset(exy, 0, sizeof(exy));
        for (i = 0; i < n; ++i)
            for (j = 0; j < n; ++j)
                if (a[i][j] & 1)
                    exx[i] = exy[j] = 1;
        for (i = 0; i < n; ++i)
            for (j = 0; j < n; ++j)
                if (!exx[i] && !exy[j] && !(a[i][j] & 1))
                    rela[i][j] = 1;
        memset(pairx, -1, sizeof(pairx));
        memset(pairy, -1, sizeof(pairy));
        for (i = 0; i < n; ++i)
            if (pairx[i] == -1) {
                memset(visited, 0, sizeof(visited));
                dfs(i, n);
            }
        for (i = 0; i < n; ++i)
            if (pairx[i] != -1)
                b[i][pairx[i]] |= 1;

        memset(rela, 0, sizeof(rela));
        memset(exx, 0, sizeof(exx));
        memset(exy, 0, sizeof(exy));
        for (i = 0; i < n; ++i)
            for (j = 0; j < n; ++j)
                if (a[i][j] & 2)
                    exx[i + j] = exy[n - 1 - i + j] = 1;
        for (i = 0; i < n; ++i)
            for (j = 0; j < n; ++j)
                if (!exx[i + j] && !exy[n - 1 - i + j] && !(a[i + j][n - 1 - i + j] & 2))
                    rela[i + j][n - 1 - i + j] = 1;
        memset(pairx, -1, sizeof(pairx));
        memset(pairy, -1, sizeof(pairy));
        for (i = 0; i < (n << 1) - 1; ++i) {
            memset(visited, 0, sizeof(visited));
            dfs(i, (n << 1) - 1);
        }
        for (i = 0; i < (n << 1) -1; ++i)
            if (pairx[i] != -1)
                b[(i - pairx[i] + n - 1) >> 1][(i + pairx[i] - (n - 1)) >> 1] |= 2;

        for (i = m = k = 0; i < n; ++i)
            for (j = 0; j < n; ++j) {
                if (b[i][j] == 3)
                    m += 2;
                else if (b[i][j])
                    m += 1;
                if (b[i][j] != a[i][j])
                        ++k;
            }
        fprintf(stdout, "%d %d\n", m, k);
        for (i = 0; i < n; ++i)
            for (j = 0; j < n; ++j)
                if (a[i][j] != b[i][j])
                    fprintf(stdout, "%c %d %d\n", b[i][j] == 3 ? 'o' : (b[i][j] == 1 ? 'x' : '+'), i + 1, j + 1);
    }
    return 0;
}

