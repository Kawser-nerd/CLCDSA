#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    if( a*b % 2 == 0) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
}