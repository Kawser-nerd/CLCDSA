#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, k, q;
    cin >> n >> k >> q;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = 2000000001;

    for(int i = 0; i < n; i++) {
        int y = a[i];

        vector<vector<int>> b(n);
        int idx = 0;
        for(int j = 0; j < n; j++) {
            if(a[j] < y) {
                idx++;
            } else {
                b[idx].push_back(a[j]);
            }
        }

        vector<int> c;

        for(int j = 0; j < n; j++) {
            sort(b[j].begin(), b[j].end());

            for(int l = 0; l < (int)b[j].size() - k + 1; l++) {
                c.push_back(b[j][l]);
            }
        }

        sort(c.begin(), c.end());

        if(c.size() >= q) {
            int x = c[q - 1];
        
            ans = min(ans, x - y);
        }
    }

    cout << ans << endl;
}