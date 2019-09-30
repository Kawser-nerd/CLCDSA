#include <iostream>

using namespace std;

int N;

int main() {
    cin >> N;
    long long pre[2];
    pre[0] = 1; pre[1] = 2;
    if (N == 1) {
        cout << 1 << endl;
        return 0;
    }
    for (int i = 1; i < N; i++) {
        long long tmp = pre[0] + pre[1];
        pre[1] = pre[0];
        pre[0] = tmp;
    }
    cout << pre[0] << endl;
}