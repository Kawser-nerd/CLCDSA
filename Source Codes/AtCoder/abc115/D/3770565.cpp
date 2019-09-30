#include <iostream>
using namespace std;

long long layer_num[51], patty_num[51];

long long getPatty(long long n, long long x) {
    if (n == 0) {
        return (x == 1 ? 1 : 0);
    } else if (x <= layer_num[n - 1] + 1) {
        return getPatty(n - 1, x - 1);
    } else if (x <= 2 * layer_num[n - 1] + 2) {
        return patty_num[n - 1] + 1 + getPatty(n - 1, x - (layer_num[n - 1] + 2));
    } else {
        return 2 * patty_num[n - 1] + 1;
    }
}

int main() {
    long long N, X;
    cin >> N >> X;

    layer_num[0] = 1;
    patty_num[0] = 1;
    for (int i = 1; i <= 50; i++) {
        layer_num[i] = 2 * layer_num[i - 1] + 3;
        patty_num[i] = 2 * patty_num[i - 1] + 1;
    }

    cout << getPatty(N, X) << endl;
}