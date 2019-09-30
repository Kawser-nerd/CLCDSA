/**
 * A - ??
 */

#include <iostream>

using namespace std;

int main() {
    int A, B, C, ans = 0;
    cin >> A >> B >> C;
    ans += C / min(A, B);
    ans += (C % min(A, B)) / max(A, B);
    cout << ans << endl;
}