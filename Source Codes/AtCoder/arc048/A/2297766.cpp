#include <iostream>

using namespace std;

int main() {

    long long a, b;
    cin >> a >> b;

    long long ans = ((a * b < 0)? b - a - 1 : b - a);
    cout << ans << endl;

    return 0;
}