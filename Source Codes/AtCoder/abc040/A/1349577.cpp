#include <iostream>

using namespace std;

int n, x;

int main() {
    cin >> n >> x;
    cout << min(x - 1, n - x) << endl;
}