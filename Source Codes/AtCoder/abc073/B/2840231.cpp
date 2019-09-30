#include <iostream>
#include <numeric>

using namespace std;

int main() {
    int n;  cin >> n;
    int sheets[100001] = { 0 };
    int l, r;
    for (int i = 0; i < n; i++) {
        cin >> l >> r;
        for (int j = l; j <= r; j++) sheets[j] = 1;
    }

    int sum = accumulate(begin(sheets), end(sheets), 0);
    cout << sum << endl;
    return 0;
}