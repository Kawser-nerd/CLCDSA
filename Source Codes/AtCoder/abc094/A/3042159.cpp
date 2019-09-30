#include <iostream>
using namespace std;

int main() {
    int A, B, X;
    cin >> A >> B >> X;

    string ans;

    if ((X <= A + B) && (A <= X)) {
        ans = "YES";
    } else {
        ans = "NO";
    }

    cout << ans << endl;
    return 0;
}