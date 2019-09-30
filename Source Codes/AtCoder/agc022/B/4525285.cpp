#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cassert>
#include <numeric>

using namespace std;

using ll = long long;

int main() {
    int n;
    cin >> n;

    vector<int> a;
    a.reserve(n);
    
    if (n >= 15000) {
        int r = n - 15000;
        for (int i = 2; i <= 30000; i++) {
            if (i % 6 == 0) {
                if (r > 0) {
                    a.push_back(i);
                    r--;
                }
            } else if (i % 2 == 0 || i % 3 == 0) {
                a.push_back(i);   
            }
        }
    } else if (n == 3) {
        a = {2, 5, 63};   
    } else {
        a.push_back(2);
        a.push_back(3);
        a.push_back(4);
        a.push_back(9);
        
        for (int i = 1; 6 * i + 2 <= 30000 && a.size() + 2 <= n; i++) {
            a.push_back(6 * i + 2);
            a.push_back(6 * i + 4);
        }
        
        for (int i = 1; 12 * i + 3 <= 30000 && a.size() + 2 <= n; i++) {
            a.push_back(12 * i + 3);
            a.push_back(12 * i + 9);
        }
        
        if (a.size() != n) {
            a.push_back(6);   
        }
    }
    
    sort(a.begin(), a.end());
    
    for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i + 1 == n];   
    }
}