#include <iostream>
using namespace std;

int main() {
    int A, B, C, D; cin >> A >> B >> C >> D;
    if(A+B == C+D) {
        cout << "Balanced" << endl;
    } else if(A+B > C+D) {
        cout << "Left" << endl;
    } else {
        cout << "Right" << endl;
    }
}