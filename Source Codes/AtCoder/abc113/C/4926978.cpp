#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cassert>
#include <memory>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
   
    struct S {
        int y, i;
    };
    
    vector<vector<S>> c(n);
    
    for (int i = 0; i < m; i++) {
        int p;
        S s;
        
        cin >> p >> s.y;
        s.i = i;
        
        c[p - 1].push_back(s);
    }
    
    vector<pair<int, int>> ans(m);
    
    for (int i = 0; i < n; i++) {
        sort(c[i].begin(), c[i].end(), [](auto x, auto y) {
            return x.y < y.y;
        });
        
        for (int j = 0; j < c[i].size(); j++) {
            ans[c[i][j].i] = make_pair(i + 1, j + 1);   
        }
    }
    
    for (int i = 0; i < m; i++) {
        printf("%06d%06d\n", ans[i].first, ans[i].second);   
    }
}