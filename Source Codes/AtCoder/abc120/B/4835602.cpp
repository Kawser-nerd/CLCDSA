#include <iostream>

using namespace std;

int main() {
    int A, B, K, i;
    cin >> A >> B >> K;
    for (i = min(A, B); K; i--) {
        if (A % i == 0 & B % i == 0) {
            K--;
        }
    }
    cout << i + 1 << endl;
}