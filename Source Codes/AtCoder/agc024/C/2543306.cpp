#include <iostream>

using namespace std;

long long N;
long long A[2 * 100000] = {0};
long long cnt = 0;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    if (A[N-1] > N-1) {
        cout << -1 << endl;
        return 0;
    }
    cnt += A[N-1];
    for (int i = N-2; i >= 0; i--) {
        if (A[i] > i || A[i+1] > A[i] + 1) {
            cout << -1 << endl;
            return 0;
        } else if (A[i] + 1 == A[i+1]) {
            continue;
        } else {
            cnt += A[i];
        }
    }
    cout << cnt << endl;
}