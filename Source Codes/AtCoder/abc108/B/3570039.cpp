#include <iostream>

using namespace std;

int main(void)
{
    int x1, y1, x2, y2, x3, y3, x4, y4;

    cin >> x1 >> y1 >> x2 >> y2;

    x3 = x2 - (y2 - y1);
    y3 = y2 + (x2 - x1);
    x4 = x3 - (x2 - x1);
    y4 = y3 - (y2 - y1);

    cout << x3 << ' ' << y3 << ' ' <<  x4 << ' ' <<  y4 << ' ' <<  endl;
    return 0;
}