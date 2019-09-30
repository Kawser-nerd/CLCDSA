#include <iostream>

using namespace std;

int main() {

    int Y;
    bool leap = false;

    cin >> Y;

    if (Y % 4 == 0) {
        leap = true;
        if (Y % 100 == 0) {
            leap = !leap;
            if (Y % 400 == 0) {
                leap = !leap;
            }
        }
    }

    cout << (leap ? "YES" : "NO") << endl;
}