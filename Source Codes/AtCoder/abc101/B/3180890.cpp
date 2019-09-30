#include <iostream>
using namespace std;

int main() {
    int n, s = 0;
    cin >> n;

    int tmp = n;
    while (tmp > 0) {
        s += tmp % 10;
        tmp /= 10;
    }

    cout << (n % s == 0 ? "Yes" : "No") << endl;
}