#include <iostream>

using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    bool winAlice = (b - (a + 1)) % 2 == 0 ? false : true;
    cout << (winAlice ? "Alice" : "Borys") << endl;

    return 0;
}