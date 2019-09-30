#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    int L[n+1], R[n+1];
    L[n] = 0; R[0] = 0;
    for (int i = 0; i < n; i++) {
        cin >> L[i] >> R[i];
    }

    sort(L, L+n+1, greater<int>());
    sort(R, R+n+1);

    long ans = 0;
    for (int i = 0; i <= n; i++) {
        ans += (long)max(0, 2*(L[i]-R[i]));
    }

    cout << ans << endl;
    return 0;
}