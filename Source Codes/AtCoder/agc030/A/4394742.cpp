#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    using ll = long long;

    ll a, b, c;
    cin >> a >> b >> c;

    cout << min(a + b + 1, c) + b << endl;
}