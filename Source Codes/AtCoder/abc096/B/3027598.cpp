#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int a[3];
    int K;

    cin >> a[0] >> a[1] >> a[2];
    cin >> K;

    sort(a, a + 3, greater<int>());

    int ans;

    ans = a[1] + a[2] + a[0] * pow(2, K);

    cout << ans << endl;
    return 0;
}