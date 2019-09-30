#include <iostream>
#include <algorithm>

using namespace std;

/*
 * 1: x < xi
 * 2: x > xi
 * 3: y < yi
 * 4: y > yi
*/

int main() {
    int w, h, n;
    cin >> w >> h >> n;

    int maxx = w;
    int minx = 0;
    int maxy = h;
    int miny = 0;
    for (int i = 0; i < n; i++) {
        int x, y, a;
        cin >> x >> y >> a;

        switch (a) {
            case 1:
                minx = max(minx, x);
                break;
            case 2:
                maxx = min(maxx, x);
                break;
            case 3:
                miny = max(miny, y);
                break;
            case 4:
                maxy = min(maxy, y);
                break;
        }
    }

    cout << max(maxx - minx, 0) * max(maxy - miny, 0) << endl;

    return 0;
}