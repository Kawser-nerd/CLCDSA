#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v(3);
    cin >> v[0] >> v[1] >> v[2];
    sort(v.begin(), v.end());
    int ans = 0;
    ans += abs(v[0] - v[1]);
    ans += abs(v[1] - v[2]);
    cout << ans << endl;
}