#include <iostream>

using namespace std;

int N;
int P[2 * 100000];
int Q[2 * 100000];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }
    for (int i = 0; i < N; i++) {
        Q[P[i]-1] = i;
    }
    int cnt = 1;
    int m = 1;
    for (int i = 1; i < N; i++) {
        if (Q[i] < Q[i-1]) {
            cnt = 1;
        } else {
            cnt += 1;
        }
        if (cnt > m) {
            m = cnt;
        }
    }
    cout << N - m << endl;
}