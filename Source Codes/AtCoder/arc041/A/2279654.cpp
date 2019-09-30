#include <iostream>

using namespace std;

int main() {

    int x, y, k;
    cin >> x >> y;
    cin >> k;

    x += min(y, k);
    k -= min(y, k);
    x -= k;

    cout << x << endl;

    return 0;
}