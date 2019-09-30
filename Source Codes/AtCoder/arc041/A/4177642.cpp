#define P(x) cout << #x" = " << x << endl
#define PP(x, y) cout << "("#x", "#y") = (" << x << ", " << y << ")" << endl
#define PPP(x, y, z) cout << "("#x", "#y", "#z") = (" << x << ", " << y << ", " << z << ")" << endl

#include <iostream>
#include <vector>

using namespace std;
int x, y, k;
int main(){
    cin >> x >> y >> k;
    if (y >= k) {
        cout << x + k << endl;
    } else {
        cout << x - (k - y) + y << endl;
    }
}