#define P(x) cout << #x" = " << x << endl
#define PP(x, y) cout << "("#x", "#y") = (" << x << ", " << y << ")" << endl
#define PPP(x, y, z) cout << "("#x", "#y", "#z") = (" << x << ", " << y << ", " << z << ")" << endl

#include <iostream>
#include <vector>

using namespace std;

double sqdist(int x1, int y1, int x2, int y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
};

int cx, cy, r;
int x1, y1, x2, y2;

int main(){
    cin >> cx >> cy >> r >> x1 >> y1 >> x2 >> y2;
    //
    if (
        cx - r >= x1 &&
        cx + r <= x2 &&
        cy - r >= y1 &&
        cy + r <= y2
    ) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
    if (
        sqdist(cx, cy, x1, y1) <= r * r &&
        sqdist(cx, cy, x1, y2) <= r * r &&
        sqdist(cx, cy, x2, y2) <= r * r &&
        sqdist(cx, cy, x2, y1) <= r * r
    ) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}