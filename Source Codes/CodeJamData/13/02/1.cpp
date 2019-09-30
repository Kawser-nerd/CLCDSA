#include <cstdio>
#include <algorithm>
using namespace std;

int grid[100][100], N, M;
int grid2[100][100];
bool solve(){
    for(int y=0; y<N; y++)
        for(int x=0; x<M; x++)
            grid2[y][x]=100;
    for(int y=0; y<N; y++)
    {
        int m=0;
        for(int x=0; x<M; x++)
            m=max(m, grid[y][x]);
        for(int x=0; x<M; x++)
            grid2[y][x]=min(m, grid2[y][x]);
    }
    for(int x=0; x<M; x++)
    {
        int m=0;
        for(int y=0; y<N; y++)
            m=max(m, grid[y][x]);
        for(int y=0; y<N; y++)
            grid2[y][x]=min(m, grid2[y][x]);
    }
    for(int y=0; y<N; y++)
        for(int x=0; x<M; x++)
            if(grid[y][x]!=grid2[y][x])
                return false;
    return true;
}

int main(){
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++)
    {
        scanf("%d %d", &N, &M);
        for(int y=0; y<N; y++)
            for(int x=0; x<M; x++)
                scanf("%d", &grid[y][x]);
        printf("Case #%d: %s\n", t, solve() ? "YES" : "NO");
    }
}
