#include <iostream>
#include <vector>

using namespace std;

int N, K;

int main(){
    cin >> N >> K;

    if (K == 0) {
        cout << (long long)N * N << endl;
        return 0;
    }

    int b = K + 1;
    int w = 1;
    long long ans = 0;
    while (b <= N) {
        ans += N / b * w;
        ans += max(w - ((N / b * b + b - N) - 1), 0);
        b++;
        w++;
    }
    cout << ans << endl;
}