#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N, X;
    int m[100];

    cin >> N >> X;
    for (int i = 0; i < N; i++){
        cin >> m[i];
    }

    sort(m, m + N);

    for (int i = 0; i < N; i++){
        X -= m[i];
    }

    int ans = N;

    ans += X/m[0];   

    cout << ans << endl;
    return 0;
}