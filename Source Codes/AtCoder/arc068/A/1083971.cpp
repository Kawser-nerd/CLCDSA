#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using lli = long long int;

int main() {
    lli x;
    cin >> x;

    lli ans = 0;

    lli tmp = x / 11;

    if (x - 11 * tmp == 0) {
        ans = 2*tmp;
    } else if (x - 11 * tmp <= 6) {
        ans = 2 * tmp + 1;
    } else {
        ans = 2 * tmp + 2;
    }

    cout << ans << endl;
    return 0;
}