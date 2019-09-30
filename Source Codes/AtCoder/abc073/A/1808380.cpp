#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(void) {
    int n;
    cin >> n;
    bool ans = (n % 10 == 9) || (n / 10 == 9);
    cout << (ans ? "Yes" : "No") << endl;
    return 0;
}