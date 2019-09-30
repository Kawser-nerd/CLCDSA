#include <iostream>
#include <complex>
#include <algorithm>

using namespace std;

int enumerateDigits(unsigned long long int target) {
    int digits = 0;
    for (; target > 0; target /= 10) ++digits;
    return digits;
}

int main() {
    unsigned long long int n;
    cin >> n;

    unsigned long long int sqrtN = (long)sqrt(n);
    
    unsigned long long int _quotient = 0;
    unsigned long long int _remainder = 0;
    for (int i = 1; i <= sqrtN; ++i) {
        if (n % i == 0) {
            _quotient = i;
            _remainder = n / i;
        }
    }

    cout << max(enumerateDigits(_quotient), enumerateDigits(_remainder)) << endl;

    return 0;
}