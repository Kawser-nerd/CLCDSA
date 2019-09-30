#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    vector<int> m(n + 1);
    
    for (int i = 2; i <= n; i++) {
        int x = i;
        for (int j = 2; j * j <= i; j++) {
            while (x % j == 0) {
                m[j]++;
                
                x /= j;
            }
        }
        
        if (x != 1) {
            m[x]++;
        }
    }
    
    long long ans = 0;
    
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = j + 1; k <= n; k++) {
                if (i != j && i != k && j != k && m[i] >=2 && m[j] >= 4 && m[k] >= 4) {
                    ans++;
                }
            }
        }
    }
    
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (i != j) {
                if (m[i] >= 2 && m[j] >= 24) {
                    ans++;
                }
                
                if (m[i] >= 4 && m[j] >= 14) {
                    ans++;
                }
            }
        }
    }
    
    for (int i = 0; i <= n; i++) {
        if (m[i] >= 74) {
            ans++;
        }
    }
    
    cout << ans << endl;
}