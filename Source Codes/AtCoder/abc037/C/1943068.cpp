/**
 * C - ??
 */

#include <iostream>

using namespace std;
using LL = long long;

int main() {

    int N, K;
    LL sub = 0, sum = 0;
    int a[100'000];

    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < K; i++) {
        sub += a[i];
    }
    sum += sub;

    for (int i = K; i < N; i++) {
        sub += a[i];
        sub -= a[i - K];
        sum += sub;
    }

    cout << sum << endl;
}