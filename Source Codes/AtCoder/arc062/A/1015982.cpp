#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    int x, y;
    int64_t A = 1, B = 1;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> x >> y;
        int64_t t = std::max((A + x-1) / x, (B + y-1) / y);
        A = x * t;
        B = y * t;
    }
    cout << A + B << std::endl;
    return 0;
}