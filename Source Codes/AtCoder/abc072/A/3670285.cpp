#include <iostream>
using namespace std;

int main() {
    long long x, t; cin >> x >> t;
    if(x-t >= 0) {
        cout << x-t << endl;
    } else {
        cout << '0' << endl;
    }
}