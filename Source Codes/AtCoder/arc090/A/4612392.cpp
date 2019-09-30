#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> b(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    for (int i = 1; i < n; i++) {
        a[i] += a[i - 1];
    }

    b[0] += a[0];

    for (int i = 1; i < n; i++) {
        b[i] += max(a[i], b[i - 1]);
    }

    cout << b[n - 1] << endl;
}