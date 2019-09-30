#include <iostream>
using namespace std;

int main() {
    int A, B; cin >> A >> B;
    if(A*B % 2 != 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}