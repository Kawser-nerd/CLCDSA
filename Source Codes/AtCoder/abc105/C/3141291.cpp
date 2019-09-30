#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;

    bool ans[1000] = {};
    while (n != 0) {
        int bit;
      	long long sum;
        if (n > 0) {
            sum = 0b01;
            for (bit = 0; n > sum; bit += 2) sum = (sum << 2) | 0b01;
            n -= (1 << bit);
        } else {
            sum = 0b10;
            for (bit = 0; abs(n) > sum; bit += 2) sum = (sum << 2) | 0b10;
            bit++;
            n -= -1 * (1 << bit);
        }
        ans[bit] = true;
    }

    int i = 1000 - 1;
    while (ans[i] == false && i > 0) i--;
    for (; i >= 0; i--) cout << (ans[i] ? 1 : 0);
    cout << endl;
}