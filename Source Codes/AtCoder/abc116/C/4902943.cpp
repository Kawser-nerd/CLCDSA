#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cassert>
#include <memory>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    
    int ans = 0;
    
    for (int i = 100; i > 0; i--) {
        for (int j = 0; j < n; j++) {
            if (h[j] == i) {
                if (j == 0 || h[j - 1] != i) {
                    ans++;
                }
            }
        }
        
        for (int j = 0; j < n; j++) {
            if (h[j] == i) {
                h[j]--;
            }
        }
    }
    
    cout << ans << endl;
}