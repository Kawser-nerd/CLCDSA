#include <iostream>
using namespace std;

int main() {
    int n, ai, count = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ai;
        while (ai % 2 == 0) {
            ai /= 2;
            count++;
        }
    }

    cout << count << endl;
}