#include <iostream>

#define MOD 1000000007LL

using namespace std;

long long A, B, C;

int main() {
    cin >> A >> B >> C;
    A %= MOD;
    B %= MOD;
    C %= MOD;
    cout << (((A * B) % MOD) * C) % MOD << endl;
}