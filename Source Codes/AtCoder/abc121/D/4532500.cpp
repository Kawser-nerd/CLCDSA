#include <iostream>

using namespace std;

long long x(long long n) {
    if (n <= 0LL) {
        return 0;
    }
    long long ans[] = {n, 1LL, n + 1, 0LL};
    return ans[n % 4];
}

int main() {
    long long a, b;
    cin >> a >> b;
    cout << (x(b) ^ x(a - 1)) << endl;
    return 0;
}