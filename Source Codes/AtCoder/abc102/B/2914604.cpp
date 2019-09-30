#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    int A[110];

    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> A[i];
    }

    sort(A, A + N);

    int ans = (A[N-1] - A[0]);

    cout << ans << endl;
    return 0;
}