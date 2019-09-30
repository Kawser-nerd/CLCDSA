//
// B - ????
//

#include <iostream>

using namespace std;

int main() {
    int L, H, N;
    cin >> L >> H >> N;
    for (int i = 0; i < N; i++) {
        int A;
        cin >> A;
        cout << (A < L ? L - A : (A > H ? -1 : 0)) << endl;
    }
}