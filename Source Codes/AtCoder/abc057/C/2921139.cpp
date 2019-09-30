#include <iostream>
#include <complex>
#include <algorithm>

using namespace std;

int main() {
    unsigned long long n;
    cin >> n;

    unsigned long long sqrtN = (long)sqrt(n);
    
    unsigned int _quotient = 0;
    unsigned int _remainder = 0;
    for (int i = sqrtN; i > 0; --i) {
        if (n % i == 0) {
            _quotient = i;
            _remainder = n / i;
            break;
        }
    }

    int ans = max((int)log10(_quotient)+1, (int)log10(_remainder)+1);
    cout << ans << endl;

    return 0;
}