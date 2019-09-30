#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, cnt = 0;
    cin >> n;
    int array[n];
    for (int &i : array) {
        cin >> i;
    }
    bool t = true;
    while (t) {
        cnt++;
        for (int &i : array) {
            if (!(i % 2)) {
                i /= 2;
            } else {
                t = false;
                break;
            }
        }
    }
    cout << cnt - 1 << endl;
    return 0;
}