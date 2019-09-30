#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i < n; i++) {
        a[i] = a[i-1] + a[i];
    }

    long ans = 0L;
    for (int i = n - k; i < n; i++) {
        long tmp = a[i];
        if (i > n - k) {
            tmp -= a[i - (n - k) - 1];
        }
        ans += tmp;
    }

    cout << ans << endl;

    return 0;
}