#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>

using namespace std;

using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<int> b;
    
    for (int i = 0; i < n; i++) {
        bool ng = true;;
        for (int j = (int)a.size() - 1; j >= 0; --j) {
            if (a[j] == j + 1) {
                b.push_back(j + 1);
                a.erase(a.begin() + j);
                
                ng = false;
                break;
            }
        }
        
        if (ng) {
            cout << -1 << endl;
            return 0;
        }
    }
    
    for (int i = n - 1; i >= 0; --i) {
        cout << b[i] << endl;
    }
}