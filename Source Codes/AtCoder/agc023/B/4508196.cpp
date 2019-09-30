#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        s[i] += s[i];
    }
    
    vector<string> tmp = s;
    
    s.insert(s.end(), tmp.begin(), tmp.end());
        
    vector<string> t(s.size(), string(2 * n, 0));
    
    for (int i = 0; i < 2 * n; i++) {
        for (int j = 0; j < 2 * n; j++) {
            t[i][j] = s[j][i];       
        }
    }
  
    int ans = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            bool ok = true;
            
            for (int k = 0; k < n; k++) {
                if (memcmp(s[i + k].c_str() + j, t[j + k].c_str() + i, n) != 0) {
                    ok = false;
                    break;
                }
            }
            
            if (ok) {
                ans++;
            }
        }
    }
    
    cout << ans << endl;
}