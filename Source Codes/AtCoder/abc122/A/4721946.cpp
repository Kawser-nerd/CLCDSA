#include <iostream>
using namespace std;

int main() {
    char b;
    cin >> b;

    if (b == 'A') {
        cout << 'T' << endl;
    } else if (b == 'C') {
        cout << 'G' << endl;
    } else if (b == 'G') {
        cout << 'C' << endl;
    } else {
        cout << 'A' << endl;
    }

    return 0;
}