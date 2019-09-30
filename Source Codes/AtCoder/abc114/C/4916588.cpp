#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cassert>
#include <set>

using namespace std;

using ll = long long;

ll n;

int dfs(ll i, bool b3 = false, bool b5 = false, bool b7 = false) {
    
    if (i > n) {
        return 0;
    }
    
    int ret = b3 && b5 && b7;
    
    ret += dfs(i * 10 + 3, true, b5, b7) + dfs(i * 10 + 5, b3, true, b7) + dfs(i * 10 + 7, b3, b5, true);
    
    return ret;
}

int main() {
    cin >> n;
    
    cout << dfs(0) << endl;
}