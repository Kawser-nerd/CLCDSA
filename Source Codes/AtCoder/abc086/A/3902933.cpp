#include <iostream>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    if ((a % 2) && (b % 2)) {
        cout << "Odd" << "\n";
    } else {
        cout << "Even "<< "\n";
    }
    return 0;
}