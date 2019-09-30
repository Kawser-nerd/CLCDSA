#define P(x) cout << #x" = " << x << endl
#define PP(x, y) cout << "("#x", "#y") = (" << x << ", " << y << ")" << endl
#define PPP(x, y, z) cout << "("#x", "#y", "#z") = (" << x << ", " << y << ", " << z << ")" << endl

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using ll = long long;

int pos[100000];
bool r[100000];
int n, l;
ll ans = 0;


ll align(int i1, int i2, int x) {
    int l = min(i1, i2);
    int r = max(i1, i2);

    bool toright = x >= pos[r];
    int start = toright ? r : l;
    int end = toright ? l : r;
    int d = toright ? -1 : 1;
    ll ans = 0;
    for (int i = start; i != end + d; i += d) {
        ans += abs(pos[i] - x);
        x += d;
    }
    return ans;
}

int main(){
    cin >> n >> l;
    for (int i = 0; i < n; ++i) {
        cin >> pos[i];
        --pos[i];
        char d;
        cin >> d;
        r[i] = d == 'R';
    }
    int lcnt = 0;
    int rcnt = 0;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        if (r[i]) rcnt++;
        else lcnt++;
        if (rcnt == 0 && lcnt > 0) {
            if (i < n - 1 && !r[i + 1]) {
                continue;
            }
            ans += align(0, lcnt - 1, 0);
            lcnt = 0;
            continue;
        }
        if (rcnt != 0 && lcnt != 0) {
            if (i < n - 1 && !r[i + 1]) {
                continue;
            }
            int rmax = i - lcnt;
            int lmin = i - lcnt + 1;
            ll rdist = align(rmax - rcnt + 1, rmax, pos[lmin] - 1) + align(lmin, i, pos[lmin]);
            ll ldist = align(rmax - rcnt + 1, rmax, pos[rmax]) + align(lmin, i, pos[rmax] + 1);

            ans += max(rdist, ldist);
            rcnt = 0;
            lcnt = 0;
        }
    }
    if (rcnt != 0) {
        ans += align(n - rcnt, n - 1, l - 1);
    }
    cout << ans << endl;
}