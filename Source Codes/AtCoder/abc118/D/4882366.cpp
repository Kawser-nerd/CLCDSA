#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cassert>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    
    vector<int> c = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    
    struct State {
        int len = -1;
        vector<int> v = vector<int>(10);
        
        bool operator <(const State& rhs) const {
            if (len != rhs.len) {
                return len < rhs.len;
            } else {
                auto w = v;
                auto rhs_w = rhs.v;
                
                reverse(w.begin(), w.end());
                reverse(rhs_w.begin(), rhs_w.end());
                
                return w < rhs_w;
            }
        }
    };
    
    vector<State> dp(n + 1);
    
    dp[0].len = 0;
    
    for (int i = 0; i < n; i++) {
        if (dp[i].len == -1) {
            continue;
        }
        
        for (int j = 0; j < m; j++) {
            if (i + c[a[j]] <= n) {
                State nxt = dp[i];
                nxt.len++;
                nxt.v[a[j]]++;
                
                dp[i + c[a[j]]] = max(dp[i + c[a[j]]], nxt);
            }
        }
    }
    
    for (int i = 9; i >= 1; i--) {
        for (int j = 0; j < dp[n].v[i]; j++) {
            cout << i;   
        }
    }
    cout << endl;
    
}