#include <iostream>
using namespace std;

int main() {
    int x, y, z; cin >> x >> y >> z;
    int ans = x / (y+z);
    if (x % (y+z) < z) ans--;
    cout << ans << endl;
    return 0;
}