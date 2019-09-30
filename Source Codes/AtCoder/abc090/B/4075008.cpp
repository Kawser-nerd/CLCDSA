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
    int A, B;
    cin >> A >> B;

    int ans = 0;
    for (int n15 = 1; n15 <= 9; ++n15) {
        for (int n24 = 0; n24 <= 9; ++n24) {
            for (int n3 = 0; n3 <= 9; ++n3) {
                int n = 10000 * n15 + 1000 * n24 + 100 * n3 + 10 * n24 + n15;
                if (A <= n && n <= B) {
                    ++ans;
                }
            }
        }
    }
    cout << ans << endl;
}