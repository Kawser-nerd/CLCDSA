#include <iostream>
using namespace std;

int main() {
    char x, y; cin >> x >> y;
    if(x - y < 0) {
        cout << '<' << endl;
    } else if(x - y == 0) {
        cout << '=' << endl;
    } else {
        cout << '>' << endl;
    }
}