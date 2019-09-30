#include <iostream>
using namespace std;

int main() {
    int n, k, x, y;
    cin >> n >> k >> x >> y;

    if( n <= k ) {
        cout << n*x << '\n';
        return 0;
    }
    else {
        cout << k*x + (n-k)*y << '\n';
        return 0;
    } 
}