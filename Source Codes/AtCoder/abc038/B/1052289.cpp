#include <iostream>

using namespace std;

int main() {
    int h1, w1, h2, w2;
    cin >> h1 >> w1 >> h2 >> w2;
    if (h1 == h2) {
        cout << "YES" << endl;
    } else if(h1 == w2) {
        cout << "YES" << endl;
    } else if(w1 == h2) {
        cout << "YES" << endl;
    } else if(w1 == w2) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}