#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> x(n), y(n);
    vector<char> c(n);
    
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> c[i];
    }
    
    vector<vector<int>> b(4 * k, vector<int>(4 * k));
    vector<vector<int>> w(4 * k, vector<int>(4 * k));
    
    for (int i = 0; i < n; i++) {
        int xi = x[i] % (2 * k);
        int yi = y[i] % (2 * k);
        
        if (c[i] == 'B') {
            b[yi][xi]++;
            b[yi + 2 * k][xi]++;
            b[yi][xi + 2 * k]++;
            b[yi + 2 * k][xi + 2 * k]++;
        } else {
            w[yi][xi]++;
            w[yi + 2 * k][xi]++;
            w[yi][xi + 2 * k]++;
            w[yi + 2 * k][xi + 2 * k]++;
        }
    }
    
    for (int i = 0; i < 4 * k; i++) {
        for (int j = 0; j < 4 * k; j++) {
            
            if (i > 0) {
                b[i][j] += b[i - 1][j];
                w[i][j] += w[i - 1][j];
            }
            
            if (j > 0) {
                b[i][j] += b[i][j - 1];
                w[i][j] += w[i][j - 1];
            }
            
            if (i > 0 && j > 0) {
                b[i][j] -= b[i - 1][j - 1];   
                w[i][j] -= w[i - 1][j - 1];
            }
        }
    }
    
    auto get = [](const vector<vector<int>>& x, int i, int j, int k, int l) {
        int ret = 0;
        
        if (k > 0 && l > 0) {
            ret += x[k - 1][l - 1];   
        
            if (i > 0 && j > 0) {
                ret += x[i - 1][j - 1];   
            }
        
            if (i > 0) {
                ret -= x[i - 1][l - 1];   
            }
            
            if (j > 0) {
                ret -= x[k - 1][j - 1];
            }
        }
        
        return ret;
    };
    
    int ans = 0;
    
    for (int i = 0; i < 2 * k; i++) {
        for (int j = 0; j < 2 * k; j++) {
            int cur = 0;
            
            cur += get(b, i, j, i + k, j + k);
            cur += get(b, i + k, j + k, i + 2 * k, j + 2 * k);
            cur += get(w, i, j + k, i + k, j + 2 * k);
            cur += get(w, i + k, j, i + 2 * k, j + k);
            
            ans = max(ans, cur);
        }
    }
    
    cout << ans << endl;
}