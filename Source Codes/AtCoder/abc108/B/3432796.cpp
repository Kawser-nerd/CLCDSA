#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2;

    x3 = y1 - y2 + x2;
    y3 = -(x1 - x2) + y2;
    x4 = -(y2 - y1) + x1;
    y4 = x2 - x1 + y1;

    cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
}