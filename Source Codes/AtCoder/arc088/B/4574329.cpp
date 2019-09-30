#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>

using namespace std;

using ll = long long;

int main() {
    string s;
    cin >> s;
    
    int n = s.size();
    
    int l = (n - 1) / 2;
    int r = n / 2;
    
    int m = 0;
    
    if (s[l] == s[r]) {
        char c = s[l];
        
        while(l >= 0 && r < n && s[l] == c && s[r] == c) {
            m = r - l + 1;
            
            l--;
            r++;
        }
    }
    
    cout << (n + m) / 2 << endl;
}