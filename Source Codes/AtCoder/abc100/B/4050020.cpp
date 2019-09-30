#include <iostream>


using namespace std;

int main() {
    int D, N;
    cin >> D >> N;

    if (N == 100) ++N;

    if (D == 0) {
        cout << N << endl;
    } else if (D == 1) {
        cout << 100 * N << endl;
    } else {
        cout << 10000 * N << endl;
    }
}