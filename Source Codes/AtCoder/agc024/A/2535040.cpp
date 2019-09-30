#include <iostream>

using namespace std;

long long A, B, C, K;

int main() {
    cin >> A >> B >> C >> K;
    if (K % 2 == 0) {
        cout << A-B << endl;
    } else {
        cout << B-A << endl;
    }
}