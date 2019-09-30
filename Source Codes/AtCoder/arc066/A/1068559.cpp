#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int main() {
    int n;
    vector<int> v;
    cin >> n;
    v.resize(n);
    map<int, int> cnt;
    for(int i = 0; i < n; ++i) {
        cin >> v[i];
        cnt[v[i]]++;
    }

    sort(v.begin(), v.end());

    for(int i = 1; n - i > 0; i += 2) {
        if (cnt[n - i] != 2) {
            cout << 0 << endl;
            return 0;
        }
    }

    if (n % 2 == 1 && cnt[0] != 1) {
        cout << 0 << endl;
        return 0;
    }

    int ans = 1;
    for (int i = 0; i < n / 2; ++i) {
        ans *= 2;
        ans %= 1000000007;
    }
    cout << ans << endl;

    return 0;
}