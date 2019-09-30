#include <iostream>
using namespace std;

using ull = unsigned long long;

ull lnum[52];
ull pnum[52];

ull countPatty(int n, ull x) {
    if (n == 0) {
        return 1;
    }
    if (x == 1) {
        return 0;
    }
    if (x <= 1 + lnum[n - 1]) {
        return countPatty(n - 1, x - 1);
    }
    if (x == lnum[n - 1] + 2) {
        return pnum[n - 1] + 1;
    }
    if (x <= 2 + lnum[n - 1] * 2) {
        return pnum[n - 1] + countPatty(n - 1, x - lnum[n - 1] - 2) + 1;
    }
    if (x == 3 + lnum[n - 1] * 2) {
        return pnum[n - 1] * 2 + 1;
    }
    exit(1);
}

int main() {
    int n;
    ull x;
    cin >> n >> x;

    lnum[0] = 1;
    pnum[0] = 1;
    for (int i = 1; i <= n; i++) {
        lnum[i] = lnum[i - 1] * 2 + 3;
        pnum[i] = pnum[i - 1] * 2 + 1;
    }

    cout << countPatty(n, x) << endl;
}