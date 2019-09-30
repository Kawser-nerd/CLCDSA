#include <iostream>

using namespace std;

int main() {
    int n, k; cin >> n >> k;
    unsigned long p = 1L * k;
    for (int i = 1; i < n; ++i) p *= k - 1;
    cout << p << endl;
    return 0;
}