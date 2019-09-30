#include <iostream>

using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    cout << ((b - a) % 2 ? "Borys" : "Alice") << endl;
}