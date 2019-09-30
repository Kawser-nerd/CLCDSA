/*
Approach:

It only makes sense to run the lawnmower at most once over each row of the grid.
For each row we can calculate the lowest setting that is possible for this row
as the minimum of the desired heights in that row.  Similarly for each column.

Then for each cell of the grid, in order to be able to cut this cell, either
the corresponding row or column height must equal the desired height of this
cell.  If all cells can be cut this way, then the answer is "YES", else "NO".
*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define REP(i,n)   FOR(i,0,n)

static int min(int x, int y) { return x < y ? x : y; }
static int max(int x, int y) { return x > y ? x : y; }

int main()
{
    int cases = 0, caseno;
    scanf("%d", &cases);
    for (caseno = 1; caseno <= cases; ++caseno)
    {
        int N = 0, M = 0;
        scanf("%d%d", &N, &M);
        int A[N][M], row[N], col[M];
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        REP(i, N) REP(j, M) {
            scanf("%d", &A[i][j]);
            row[i] = max(row[i], A[i][j]);
            col[j] = max(col[j], A[i][j]);
        }
        bool answer = true;
        REP(i, N) REP(j, M) answer &= A[i][j] == min(row[i], col[j]);
        printf("Case #%d: %s\n", caseno, answer ? "YES" : "NO");
    }
    return 0;
}
