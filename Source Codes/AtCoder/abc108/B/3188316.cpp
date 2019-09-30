#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()

{
    int x1, x2, y1, y2;
    int x3, y3, x4, y4;
    int sides;
    cin >> x1 >> y1 >> x2 >> y2;

    sides = abs(x1 * x1 + y1 + y1 - x2 * x2 - y2 * y2);
    int yy = y2 - y1;
    int xx = x2 - x1;
    x3 = x2 - yy;
    y3 = y2 + xx;
    x4 = x3 - xx;
    y4 = y3 - yy;
    cout << x3 << " " << y3 << " " << x4 << " " << y4;
}