#include <iostream>

using namespace std;

long long f(long long a) {
    if (a % 4 == 0) {
        return a * 1LL;
    } else if (a % 4 == 1) {
        return 1LL;
    } else if (a % 4 == 2) {
        return a * 1LL + 1LL;
    } else {
        return 0LL;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    long long a, b;
    cin >> a >> b;
    cout << (f(b * 1LL) ^ f(a * 1LL - 1LL)) << '\n';

    return 0;
}