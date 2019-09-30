#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int a[10000];
vector <int> v[10000];
map <pair<int, int>, int> mp;
map <pair<int, int>, int> mp2;

int check(int x1, int y1, int x2, int y2)
{
    if (mp2.count(make_pair(x1, x2))) return mp2[make_pair(x1, x2)];
    
    int i, j;
    vector <int> w(v[x1].size(), 0);
    
    if (v[x1].size() != v[x2].size()) return mp2[make_pair(x1, x2)] = 0;
    
    for (i = 0; i < v[x1].size(); i++) {
        if (v[x1][i] == y1) continue;
        
        for (j = 0; j < v[x2].size(); j++) {
            if (w[j] == 1 || v[x2][j] == y2 || a[v[x1][i]] != a[v[x2][j]]) continue;
            
            if (check(v[x1][i], x1, v[x2][j], x2) == 1) {
                w[j] = 1;
                
                break;
            }
        }
        
        if (j == v[x2].size()) return mp2[make_pair(x1, x2)] = 0;
    }
    
    return mp2[make_pair(x1, x2)] = 1;
}

int dfs(int x, int y)
{
    if (mp.count(make_pair(x, y))) return mp[make_pair(x, y)];
    
    int c = v[x].size(), i, j, k;
    
    if (y != -1) c--;
    
    if (c == 0) return mp[make_pair(x, y)]= 1;
    
    if (c % 2 == 1) {
        for (i = 0; i < v[x].size(); i++) {
            if (v[x][i] == y) continue;
            
            if (dfs(v[x][i], x) == 1) {
                vector <int> w(v[x].size(), 0);
                
                w[i] = 1;
                
                for (j = 0; j < v[x].size(); j++) {
                    if (w[j] == 1 || v[x][j] == y) continue;
                    
                    for (k = j + 1; k < v[x].size(); k++) {
                        if (w[k] == 1 || v[x][k] == y || a[v[x][j]] != a[v[x][k]]) continue;
                        
                        if (check(v[x][j], x, v[x][k], x) == 1) {
                            w[j] = w[k] = 1;
                            
                            break;
                        }
                    }
                    
                    if (k == v[x].size()) break;
                }
                
                if (j == v[x].size()) return mp[make_pair(x, y)] = 1;
            }
        }
    } else {
        vector <int> w(v[x].size(), 0);
        
        for (i = 0; i < v[x].size(); i++) {
            if (w[i] == 1 || v[x][i] == y) continue;
            
            for (j = i + 1; j < v[x].size(); j++) {
                if (w[j] == 1 || v[x][j] == y || a[v[x][i]] != a[v[x][j]]) continue;
                
                if (check(v[x][i], x, v[x][j], x) == 1) {
                    w[i] = w[j] = 1;
                    
                    break;
                }
            }
            
            if (j == v[x].size()) return mp[make_pair(x, y)] = 0;
        }
        
        return mp[make_pair(x, y)] = 1;
    }
    
    return mp[make_pair(x, y)] = 0;
}

int main()
{
    int t, i;
    
    scanf("%d", &t);
    
    for (i = 0; i < t; i++) {
        int n, f = 0, j, k;
        char s[2];
        
        scanf("%d", &n);
        
        for (j = 0; j < n; j++) {
            scanf("%s", s);
            
            a[j] = s[0] - 'A';
        }
        
        for (j = 0; j < n; j++) v[j].clear();
        
        mp.clear();
        mp2.clear();
        
        for (j = 0; j < n - 1; j++) {
            int x, y;
            
            scanf("%d %d", &x, &y);
            
            x--;
            y--;
            
            v[x].push_back(y);
            v[y].push_back(x);
        }
        
        for (j = 0; j < n; j++) {
            if (f == 0) f = dfs(j, -1);
        }
        
        if (n % 2 == 0) {
            for (j = 0; j < n; j++) {
                for (k = 0; k < v[j].size(); k++) {
                    if (j > v[j][k] && a[j] == a[v[j][k]] && f == 0) f = check(j, v[j][k], v[j][k], j);
                }
            }
        }
        
        if (f == 1) {
            printf("Case #%d: SYMMETRIC\n", i + 1);
        } else {
            printf("Case #%d: NOT SYMMETRIC\n", i + 1);
        }
    }
    
    return 0;
}
