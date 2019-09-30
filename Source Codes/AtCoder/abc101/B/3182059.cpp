#include <iostream>
using namespace std;

int getSumOfDigit(int n) {
    return (n > 0 ? (n % 10) + getSumOfDigit(n / 10) : 0);
}

int main() {
    int n;
    cin >> n;

    cout << (n % getSumOfDigit(n) == 0 ? "Yes" : "No") << endl;
}