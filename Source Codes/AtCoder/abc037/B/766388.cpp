#include <iostream>

using namespace std;

int main() {

    int n, q;
    cin >> n >> q;
    int array[n];

    for (int i = 0; i < n; i++) {
        array[i] = 0;
    }

    for (int j = 0; j < q; j++) {
        int l, r, t;
        cin >> l >> r >> t;

        for (int k = l; k <= r; k++) {
            array[k-1] = t;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << array[i] << endl;
    }

    return 0;

}