#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    if (A > B) {
        cout << C / B << endl;
    } else {
        cout << C / A << endl;
    }
}