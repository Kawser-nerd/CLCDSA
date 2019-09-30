#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <set>
#include <string>

using namespace std;

int main() {
    int X;
    cin >> X;

    int ans = 1;
    for (int b = 2; b <= X; ++b) {
        for (int p = 2; ; ++p) {
            int pow = 1;
            for (int i = 0; i < p; ++i) {
                pow *= b;
            }
            if (pow > X) break;
            ans = max(ans, pow);
        }
    }
    cout << ans << endl;
}