#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <tuple>
#include <stdbool.h>
#include <bitset>
#include <string>

using namespace std;

int main(void) {
    int n, m, c;
    cin >> n;
    cin >> m;
    cin >> c;
    vector<int> b(m);
    for(int i = 0 ; i < m ; ++i) {
        cin >> b[i];
    }
    int ans = 0;
    for(int j = 0 ; j < n ; ++j) {
        int spec = c;
        for(int i = 0 ; i < m ; ++i) {
            int a;
            cin >> a;
            spec += a * b[i];
        }
        if (spec > 0) {
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}