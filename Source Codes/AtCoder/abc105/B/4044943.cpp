#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    bool ans = false;
    for (int y = 0; y < 100; ++y) {
        int tmp = N - 7 * y;
        if (tmp < 0) break;
        if (tmp % 4 == 0) {
            ans = true;
            break;
        }
    }
    if (ans) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}