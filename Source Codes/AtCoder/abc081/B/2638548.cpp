#include <iostream>
using namespace std;

int main() {
    int N;
    int A[200];
    int cnt = 0;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    while (true) {
        bool odd = false;
        for (int i = 0; i < N; i++) {
            if (A[i] % 2 != 0) {
                odd = true;
            }
        }
        if (odd) {
            break;
        }

        for (int i = 0; i < N; i++) {
            A[i] = A[i] / 2;
        }
        cnt++;
    }

    cout << cnt << endl;
    
    return 0;
}