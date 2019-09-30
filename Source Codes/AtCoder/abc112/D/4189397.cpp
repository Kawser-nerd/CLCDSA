#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    long long ans = 1;

    for (long long i = 1; i * i <= m; i++) {
        if (m % i == 0) {
            if (n <= m / i) {
                ans = max(ans, i);
            }

            if (n <= m / (m / i)) {
                ans = max(ans, m / i);
            }
        } 
    }

    cout << ans << endl;
}