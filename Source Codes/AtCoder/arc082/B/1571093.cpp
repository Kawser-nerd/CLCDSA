#include <iostream>

using namespace std;

int main() {
    int n, c{0}, a;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        if (a == i) {
            c++;
            i++;
            cin >> a;
        }
    }
    cout << c;
}