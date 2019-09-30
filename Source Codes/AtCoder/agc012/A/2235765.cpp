#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int n;
    long long ans = 0;
    vector<int> a;
    cin >> n;
    a.resize(n * 3);
    for (int i = 0; i < n * 3; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++)
        ans += a[n + i * 2];
    cout << ans << endl;
}