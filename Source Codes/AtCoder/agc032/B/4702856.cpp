#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> a, b;

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (i + j != n + !(n % 2)) {
                a.push_back(i);
                b.push_back(j);
            }
        }
    }

    cout << a.size() << endl;

    for (int i = 0; i < a.size(); ++i) {
        cout << a[i] << ' ' << b[i] << endl;
    }
}