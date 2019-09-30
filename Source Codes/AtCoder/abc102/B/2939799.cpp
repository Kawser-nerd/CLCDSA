#include <iostream>

using namespace std;

int N;
int A[100];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int ans = -1;
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            ans = max(ans, abs(A[i] - A[j]));
        }
    }
    cout << ans << endl;
}