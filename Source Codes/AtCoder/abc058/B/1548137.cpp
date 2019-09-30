//
// B - ???
//

#include <iostream>

using namespace std;

int main() {

    string O, E;
    cin >> O;
    cin >> E;

    for (int i = 0; i < O.length() + E.length(); i++) {
        if (i % 2) {
            cout << E[i / 2];
        } else {
            cout << O[i / 2];
        }
    }
    cout << endl;
}