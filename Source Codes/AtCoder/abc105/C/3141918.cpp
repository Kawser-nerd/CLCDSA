#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;

    bool s[30] = {};
    int i = 0;
    long long mod = 2;

    while (n != 0) {
        if (n % mod) {
            s[i] = true;
            n -= pow(-2, i);
        }
        i++;
        mod *= 2;
    }

    for (i -= 1; i > 0; i--) cout << s[i];
    cout << s[0] << endl;
}