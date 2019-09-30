#include <stdio.h>
#include <string.h>
#include <algorithm>

struct Point {
    int x, y, h;
    Point(){}
    Point(int _x, int _y, int _h) : x(_x), y(_y), h(_h) {}
}sort[11000];

int m, n, inp[110][110], vis[110][110];

bool cmp(const Point& a, const Point& b) {
    return a.h<b.h;
}

int main() {
    int casN;
    scanf("%d", &casN);
    for (int casI = 0; casI < casN; casI++) {
        scanf("%d%d", &m, &n);
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                scanf("%d", &inp[i][j]);
                sort[i*n+j] = Point(i, j, inp[i][j]);
            }
        }
        std::sort(sort, sort+m*n, cmp);

        bool ans = true;
        memset(vis, 0, sizeof(vis));
        for (int i=0; i<m*n; i++) {
            if (!vis[sort[i].x][sort[i].y]) {
                bool found = true, found2 = true;
                for (int j=0; j<n; j++) {
                    if (inp[sort[i].x][j] > sort[i].h) {
                        found = false;
                        break;
                    }
                }
                for (int j=0; j<m; j++) {
                    if (inp[j][sort[i].y] > sort[i].h) {
                        found2 = false;
                        break;
                    }
                }
                if (!found && !found2) {
                    ans = false;
                    break;
                }
                if (found) {
                    for (int j=0; j<n; j++) {
                        vis[sort[i].x][j] = 1;
                    }
                }
                if (found2) {
                    for (int j=0; j<m; j++) {
                        vis[j][sort[i].y] = 1;
                    }
                }
            }
        }

        printf("Case #%d: %s\n", casI+1, ans ? "YES" : "NO");
    }
    return 0; 
}
