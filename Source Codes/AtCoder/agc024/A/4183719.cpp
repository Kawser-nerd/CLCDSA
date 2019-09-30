#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long A, B, C, K;
    cin >> A >> B >> C >> K;
    
//    for (int i {1}; i <= K; ++i) {
//        int a {A}, b{B}, c{C};
//        A = b + c;
//        B = a + c;
//        C = a + b;
//    }
    if (abs(A - B) > pow(10, 18)) {
        cout << "Unfair" << endl;
    } else {
        if (K % 2 == 0) {
            cout << A - B << endl;
        } else {
            cout << B - A << endl;
        }
    }
    
    return 0;
}