#include <iostream>

using namespace std;

int main() {

    int n;
    cin >> n;

    bool isPrime = true;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            isPrime = false;
            break;
        }
    }
    cout << ((isPrime)? "YES" : "NO") << endl;

    return 0;
}