#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>

using namespace std;
using ll = long long;

int n;

int main(){
    map<int, int> m;

    cin >> n;

    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        auto key = m.find(a);
        if (key != m.end()) {
            m[a]++;
        } else {
            m[a] = 1;
        }
    }

    int ans = 0;
    for (auto itr = m.begin(); itr != m.end(); ++itr) {
        int a = itr->first;
        int cnt = itr->second;
        //cout << a << ", " << cnt << ", " << abs(a - cnt) << endl;
        ans += cnt >= a ? cnt - a : cnt;
    }
    cout << ans << endl;
}