#include <iostream>

using namespace std;

int main()
{
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    int x3 = 0, y3 = 0, x4 = 0, y4 = 0;

    x3 = x2 + y1 - y2;
    y3 = y2 + x2 - x1;
    x4 = x1 + y1 - y2;
    y4 = x2 + y1 - x1;

    cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
    return 0;
}