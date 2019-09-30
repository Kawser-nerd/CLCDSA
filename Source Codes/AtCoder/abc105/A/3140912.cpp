#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    cout << (n % k ? 1 : 0) << endl;
}