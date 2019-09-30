#include <iostream>
#include <vector>
using namespace std;

int main () {

    int n;
    cin >> n;

    int max_n = 55555;
    bool prime[max_n + 1];
    for (int i = 0; i <= max_n; i++) {
        prime[i] = true;
    }
    for (int i = 2; i <= max_n; i++) {
        if (prime[i]) {
            for (int j = i + i; j <= max_n; j += i) {
                prime[j] = false;
            }
        }
    }

    vector<int> ans;
    for (int i = 11; i <= max_n; i++) {
        if (prime[i] && i % 5 == 1) {
            ans.push_back(i);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i];
        
        if (i == n - 1) cout << endl;
        else cout << " ";
    }

    return 0;
}