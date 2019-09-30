#include <iostream>
using namespace std;

int main() {
    int a, b; cin >> a >> b;
    if(a <= b) {
        cout << a  << endl;
    } else {
        cout << a - 1 << endl;
    }
}