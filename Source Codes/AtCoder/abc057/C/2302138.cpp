#include <iostream>
#include <cmath>

using namespace std;

int cntDigit(unsigned long long n) {
    int digit = 1;
    while (n >= 10) {
        digit += 1;
        n /= 10;
    }
    return digit;
}

int main() {
    // int N;
    unsigned long long N;
    int num;

    cin >> N;

    num = cntDigit(N);

    for (unsigned long long A = 1; A * A <= N; ++A) {
        if (N % A == 0) {
            // cout << A << endl;
            unsigned long long B = N / A;
            num = min(num, cntDigit(B));
        }
    }

    cout << num << endl;

    return 0;
}