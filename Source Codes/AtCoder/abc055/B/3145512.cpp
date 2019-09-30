#include <iostream>

#define MOD 1000000007

using namespace std;



int main() {
    int n; cin >> n;

    unsigned long power = 1;

    for (int i = 1; i <= n; ++i) power = power * i % MOD;

    cout << power << endl;

    return 0;
}