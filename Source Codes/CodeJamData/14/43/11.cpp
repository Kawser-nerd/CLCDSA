#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int a[1000][4];
int d[1002][1002];
long long f[1002];

int cross(int x1, int x2, int x3, int x4)
{
    if (x1 >= x3 && x1 <= x4) return 1;
    if (x2 >= x3 && x2 <= x4) return 1;
    if (x3 >= x1 && x3 <= x2) return 1;
    if (x4 >= x1 && x4 <= x2) return 1;
    
    return 0;
}

int main()
{
    int t, i;
    
    scanf("%d", &t);
    
    for (i = 0; i < t; i++) {
        int w, h, b, j, k;
        long long ans;
        priority_queue <pair<long long, int> > q;
        
        scanf("%d %d %d", &w, &h, &b);
        
        for (j = 0; j < b; j++) scanf("%d %d %d %d", &a[j][0], &a[j][1], &a[j][2], &a[j][3]);
        
        for (j = 0; j < b; j++) {
            d[j][j] = 0;
            
            for (k = j + 1; k < b; k++) {
                if (cross(a[j][0], a[j][2], a[k][0], a[k][2])) {
                    if (a[j][3] < a[k][1]) {
                        d[j][k] = d[k][j] = a[k][1] - a[j][3] - 1;
                    } else {
                        d[j][k] = d[k][j] = a[j][1] - a[k][3] - 1;
                    }
                } else if (cross(a[j][1], a[j][3], a[k][1], a[k][3])) {
                    if (a[j][2] < a[k][0]) {
                        d[j][k] = d[k][j] = a[k][0] - a[j][2] - 1;
                    } else {
                        d[j][k] = d[k][j] = a[j][0] - a[k][2] - 1;
                    }
                } else {
                    if (a[j][3] < a[k][1]) {
                        if (a[j][2] < a[k][0]) {
                            d[j][k] = d[k][j] = max(a[k][1] - a[j][3] - 1, a[k][0] - a[j][2] - 1);
                        } else {
                            d[j][k] = d[k][j] = max(a[k][1] - a[j][3] - 1, a[j][0] - a[k][2] - 1);
                        }
                    } else {
                        if (a[j][2] < a[k][0]) {
                            d[j][k] = d[k][j] = max(a[j][1] - a[k][3] - 1, a[k][0] - a[j][2] - 1);
                        } else {
                            d[j][k] = d[k][j] = max(a[j][1] - a[k][3] - 1, a[j][0] - a[k][2] - 1);
                        }
                    }
                }
            }
            
            d[j][b] = d[b][j] = a[j][0];
            d[j][b + 1] = d[b + 1][j] = w - a[j][2] - 1;
        }
        
        d[b][b] = d[b + 1][b + 1] = 0;
        d[b][b + 1] = d[b + 1][b] = w;
        
        for (j = 0; j < b + 2; j++) f[j] = 1e18;
        
        f[b] = 0;
        q.push(make_pair(0, b));
        
        while (!q.empty()) {
            long long x = -q.top().first;
            int y = q.top().second;
            
            q.pop();
            
            if (f[y] != x) continue;
            
            if (y == b + 1) {
                ans = x;
                
                break;
            }
            
            for (j = 0; j < b + 2; j++) {
                if (x + d[y][j] < f[j]) {
                    f[j] = x + d[y][j];
                    q.push(make_pair(-f[j], j));
                }
            }
        }
        
        printf("Case #%d: %lld\n", i + 1, ans);
    }
    
    return 0;
}
