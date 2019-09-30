#define P(x) cout << #x" = " << x << endl
#define PP(x, y) cout << "("#x", "#y") = (" << x << ", " << y << ")" << endl
#define PPP(x, y, z) cout << "("#x", "#y", "#z") = (" << x << ", " << y << ", " << z << ")" << endl

#include <iostream>
#include <vector>
#include <set>

using namespace std;
using PA = pair<int, int>;
using ll = long long;

int pre[100000];
int last[100000];
int n, k;
vector<PA> arr;
set<int> used;

int main(){
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int t, d;
        cin >> t >> d;
        t--;
        arr.push_back(make_pair(d, t));
        last[i] = -1;
    }
    sort(arr.begin(), arr.end(), greater<PA>());

    for (int i = 0; i < n; i++) {
        // int d = arr[i].first;
        int t = arr[i].second;
        pre[i] = last[t];
        last[t] = i;
        // PPP(i, t, pre[i]);
    }
    int nex = k - 1;
    ll types = 0;
    ll sm = 0;
    for (int i = 0; i < k; ++i) {
        int d = arr[i].first;
        if (pre[i] == -1) {
            types++;
        }
        sm += d;
    }
    ll ans = sm + types * types;
    int i = k;
    while(true) {
        if (nex == -1) {
            break;
        }
        if (pre[nex] == -1) {
            nex--;
            continue;
        }
        while (i < n && pre[i] != -1) {
            i++;
        }
        if (i == n) break;
        types += 1;
        sm -= arr[nex].first;
        sm += arr[i].first;
        ans = max(ans, sm + types * types);
        nex -= 1;
        i += 1;
    }
    cout << ans << endl;
}