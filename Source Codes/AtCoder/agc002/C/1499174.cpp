#include <iostream>
#include <vector>
#include <cassert>
#define repeat(i,n) for (int i = 0; (i) < (n); ++(i))
#define repeat_from_reverse(i,m,n) for (int i = (n)-1; (i) >= (m); --(i))
typedef long long ll;
using namespace std;
int main() {
    int n; ll l; cin >> n >> l;
    vector<ll> a(n); repeat (i,n) cin >> a[i];
    vector<int> ans;
    repeat (i,n-1) {
        if (a[i] + a[i+1] >= l) {
            repeat (j,i) ans.push_back(j);
            repeat_from_reverse (j,i,n-1) ans.push_back(j);
            break;
        }
    }
    if (ans.empty()) {
        assert (n >= 2);
        cout << "Impossible" << endl;
    } else {
        cout << "Possible" << endl;
        for (int i : ans) cout << i+1 << endl;
    }
    return 0;
}