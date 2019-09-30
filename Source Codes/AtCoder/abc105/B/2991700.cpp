#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    int m;
    bool flg = false;
    for (int i = 0; i < (N / 4) + 1; i++) {
        m = N - 4 * i;
        if (m % 7 == 0) {
            flg = true;
        }
    }
    if (flg) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}