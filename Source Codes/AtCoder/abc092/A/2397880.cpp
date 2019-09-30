/**
 * A - Traveling Budget
 */

#include <iostream>

using namespace std;

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    int ans = 1 << 29;
    ans = min(ans, A + C);
    ans = min(ans, A + D);
    ans = min(ans, B + C);
    ans = min(ans, B + D);
    cout << ans << endl;
}