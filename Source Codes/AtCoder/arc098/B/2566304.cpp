#include <iostream>
#include <vector>

using namespace std;

int n;
int a[200000];

int bit = 0;

int main(){
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int l = 0;
    int r = 0;

    bit = a[0];
    long long ans = 0;

    // for (int i = 0; i < n; ++i) {
    //     cout << i << " ";
    //     for (int k = 19; k >= 0; k--) {
    //         cout << (a[i] >> k & 1);
    //     }
    //     cout << endl;
    // }
    while(l < n - 1 && r < n - 1) {
        // cout << l << ", "<< r << endl;
        // for (int k = 19; k >= 0; k--) {
        //     cout << (bit >> k & 1);
        // }
        // cout << endl;
        if ((a[r + 1] ^ bit) != (a[r + 1] + bit)) {
            int w = r - l + 1;
            ans += w;
            // cout << "can't go, add " << w << "ans = " << ans << endl;
            bit = bit - a[l];
            l++;
            if (l > r) {
                r = l;
                bit = a[r];
            }
        } else {
            r++;
            bit = a[r] ^ bit;
        }
    }

    // cout << endl << l << " " << r << endl;
    int w = r - l + 1;
    ans += (long long)w * (w + 1) / 2;

    cout << ans << endl;
}