#include <iostream>

#define MAX 100100

using namespace std;

// ????????
bool prime[MAX];
// ???
int sum[MAX];

void calcPrime();
bool isPrime(int);

int main() {
    calcPrime();
    int q; cin >> q;

    for (int i = 0; i < q; ++i) {
        int l, r; cin >> l >> r;
        cout << (sum[r] - sum[l - 1]) << endl;
    }

    return 0;
}

void calcPrime() {
    for (int i = 0; i < MAX; ++i) prime[i] = true;
    prime[0] = prime[1] = false;

    for (int i = 2; i * i < MAX; ++i) {
        if (!prime[i]) continue;
        for (int j = i; j * i < MAX; ++j) {
            prime[i * j] = false;
        }
    }

    for (int i = 0; i < MAX; ++i) {
        sum[i] = sum[i - 1] + (isPrime(i) ? 1 : 0);
    }
}

bool isPrime(int x) {
    return prime[x] && prime[(x + 1) / 2];
}