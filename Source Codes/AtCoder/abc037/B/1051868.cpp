#include <iostream>

using namespace std;

int main() {
    int n;
    int q;
    cin >> n >> q;
    int as[n];
    for(int i = 0; i < n; i++) {
        as[i] = 0;
    }
    for(int i = 0; i < q; i++) {
        int l, r, t;
        cin >> l >> r >> t;
        for(int j = l; j <= r; j++) {
            as[j - 1] = t;
        }
    }
    for(int i = 0; i < n; i++) {
        cout << as[i] << endl;
    }
}