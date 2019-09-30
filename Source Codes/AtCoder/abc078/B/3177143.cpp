#include <iostream>

using namespace std;

int main() {
    int x, y, z; cin >> x >> y >> z;
    int ans = x - z;
    ans /= (y + z);
    cout << ans << endl;
    return 0;
}