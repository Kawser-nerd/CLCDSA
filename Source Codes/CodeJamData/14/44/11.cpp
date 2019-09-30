#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int mod = 1000000007;
long long c[101][101];
char s[101];
vector <string> v;

pair<int, int> dfs(int x, int y, int z, int w)
{
    int m = 0, i, j;
    long long ans = 0, num = 0;
    vector <int> v2;
    
    for (i = x; i < y; i++) {
        for (j = i; j < y; j++) {
            if (v[i][z] != v[j][z]) break;
        }
        
        v2.push_back(j - i);
        m = max(m, j - i);
        i = j - 1;
    }
    
    if (m < w) {
        for (i = m; i <= w; i++) {
            long long tmp = c[w][i];
            
            for (j = 0; j < v2.size(); j++) tmp = tmp * c[i][v2[j]] % mod;
            
            if ((w - i) & 1) {
                num -= tmp;
            } else {
                num += tmp;
            }
            
            if (num < 0) num += mod;
            num %= mod;
        }
    } else {
        long long tmp = 1;
        
        for (i = 0; i < v2.size(); i++) {
            if (v2[i] < w) tmp = tmp * c[w][v2[i]] % mod;
        }
        
        num += tmp;
    }
    
    for (i = x; i < y; i++) {
        for (j = i; j < y; j++) {
            if (v[i][z] != v[j][z]) break;
        }
        
        if (i + 1 == j) {
            ans += v[i].size() - z;
        } else {
            pair<int, int> p = dfs(i, j, z + 1, min(j - i, w));
            
            ans += p.first + min(j - i, w);
            num = num * p.second % mod;
        }
        
        i = j - 1;
    }
    
    return make_pair(ans, num);
}

int main()
{
    int t, i, j;
    
    for (i = 0; i <= 100; i++) {
        c[i][0] = c[i][i] = 1;
        
        for (j = 1; j < i; j++) c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
    }
    
    scanf("%d", &t);
    
    for (i = 0; i < t; i++) {
        int n, m;
        pair<int, int> p;
        
        scanf("%d %d", &n, &m);
        
        v.clear();
        
        for (j = 0; j < n; j++) {
            scanf("%s", s);
            
            v.push_back((string)s);
        }
        
        sort(v.begin(), v.end());
        
        p = dfs(0, n, 0, m);
        
        printf("Case #%d: %d %d\n", i + 1, p.first + m, p.second);
    }
    
    return 0;
}
