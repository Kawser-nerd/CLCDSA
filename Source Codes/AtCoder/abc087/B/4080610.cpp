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
    int A, B, C, X;
    cin >> A >> B >> C >> X;

    int ans = 0;
    for (int a = 0; a <= A; ++a) {
        for (int b = 0; b <= B; ++b) {
            for (int c = 0; c <= C; ++c) {
                if (500 * a + 100 * b + 50 * c == X) {
                    ++ans;
                }
            }
        }
    }
    cout << ans << endl;
}