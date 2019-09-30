#include <iostream>
#include <cmath>
# define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;


long long f(long long x) {
    long long ret = 0;
    long long d = 1 + log10(x);
    for (long long i=1; i<=d; i++) {
        long long factor = pow(10, i);
        long long denominator = pow(10, i-1);
        ret += (x % factor) / denominator;
    }
    return ret;
}


int main() {
    long long n; cin >> n;
    if (n % f(n) == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}