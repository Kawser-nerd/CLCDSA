/**
 * B - ??
 */

#include <iostream>

using namespace std;

int main() {

    int N, Q;
    int a[101] = {0};

    cin >> N >> Q;

    for (int i = 0; i < Q; i++) {
        int L, R, T;
        cin >> L >> R >> T;
        for (int j = L; j <= R; j++) {
            a[j] = T;
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << a[i] << endl;
    }
}