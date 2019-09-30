#include <iostream>
using namespace std;

int main() {
    int r;
    cin >> r;

    cout << (r < 1200 ? "ABC" : r < 2800 ? "ARC" : "AGC") << endl;
}