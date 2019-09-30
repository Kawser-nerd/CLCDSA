#include <iostream>
using namespace std;

int main() {
    int N; cin >> N;
    if (N % 2 == 0) {
        cout << N << endl;
    } else {
        cout << 2 * N << endl;
    }
}