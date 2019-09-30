#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long ans = 0;

    long long r = 0;
    int s = 0;
    for(int l = 0; l < n; l++) {
        while(r < n && (s & a[r]) == 0) {
            s ^= a[r];
            r++;
        }

        ans += r - l;

        s ^= a[l];
    }

    cout << ans << endl;
}