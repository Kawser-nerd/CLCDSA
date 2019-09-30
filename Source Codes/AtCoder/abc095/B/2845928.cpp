#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    int minM = INT_MAX;
    for (int i = 0; i < n; i++) {
        int mi; cin >> mi;
        minM = min(mi, minM);
        x -= mi;
    }

    cout << n + x / minM << endl;

    return 0;
}