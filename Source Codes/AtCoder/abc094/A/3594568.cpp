#include <iostream>
using namespace std;

int main() {
    int A, B, X; cin >> A >> B >> X;
    if(X - A >= 0 && X - A <= B) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}