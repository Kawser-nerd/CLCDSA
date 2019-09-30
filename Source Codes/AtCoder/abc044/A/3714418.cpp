#include <iostream>
using namespace std;

int main() {
    int n, k, x, y; cin >> n >> k >> x >> y;
    if(n >= k) {
        cout << k*x + (n-k)*y << endl;
    } else {
        cout << n*x << endl;
    }
}