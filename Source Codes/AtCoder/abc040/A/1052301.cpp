#include <iostream>

using namespace std;

int main() {
    int n;
    int x;
    cin >> n >> x;
    if (x == 1) {
        cout << 0 << endl;
    } else if((x - 1) > (n - x)){
        cout << n - x << endl;
    } else {
        cout << x - 1 << endl;
    }
}