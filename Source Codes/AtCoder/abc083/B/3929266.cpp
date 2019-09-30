#include <iostream>

using namespace std;
int n, a, b, p = 0;


int main() {
    cin >> n >> a >> b;
    int s = -1;
    for (int i = 1; i < n + 1; i++) {
        if (i < 10) {
            s = i;
        } else if (i < 100) {
            s = i / 10 + i % 10;
        } else if (i < 1000) {
            s = i / 100 + (i % 100) / 10 + i % 10;
        } else if (i < 10000) {
            s = i / 1000 + (i % 1000) / 100 + (i % 100) / 10 + i % 10;
        } else {
            s = 1;
        }
        if (a <= s && s <= b) {
            p += i;
        }
    }
    cout << p << endl;
    return 0;
}