#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;
using ull = unsigned long long;

int main() {
    int X, Y, Z;
    cin >> X >> Y >> Z;

    int rest = X - Z;
    int ans = 0;
    while (true) {
        if (rest - Y - Z >= 0) {
            rest -= Y + Z;
            ++ans;
        } else {
            break;
        }
    }
    cout << ans << endl;
}