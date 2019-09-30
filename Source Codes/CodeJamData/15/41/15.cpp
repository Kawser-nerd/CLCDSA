#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 105;

int n, m;

char map[N][N];

const int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

const int INF = 1000000000;

int getDir(char ch) {
    if (ch == '^') {
        return 0;
    } else if (ch == 'v') {
        return 1;
    } else if (ch == '<') {
        return 2;
    } else {
        return 3;
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int ans = 0;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i) {
            scanf("%s", map[i]);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (map[i][j] == '.') {
                    continue;
                } 
                bool has[4];
                for (int d = 0; d < 4; ++d) {
                    has[d] = false;
                    int tx = i, ty = j;
                    while (tx >= 0 && tx < n && ty >= 0 && ty < m) {
                        tx += dx[d], ty += dy[d];
                        if (tx >= 0 && tx < n && ty >= 0 && ty < m && map[tx][ty] != '.') {
                            break;
                        }
                    }
                    if (tx >= 0 && tx < n && ty >= 0 && ty < m) {
                        has[d] = true;
                    }
                }
                if (!has[0] && !has[1] && !has[2] && !has[3]) {
                    ans = INF;
                } else if (has[getDir(map[i][j])]) {
                    ans += 0;
                } else {
                    ans += 1;
                }
            }
        }
        static int id = 0;
        printf("Case #%d: ", ++id);
        if (ans >= INF) {
            printf("IMPOSSIBLE\n");
        } else {
            printf("%d\n", ans);
        }
    }
    return 0;
}
