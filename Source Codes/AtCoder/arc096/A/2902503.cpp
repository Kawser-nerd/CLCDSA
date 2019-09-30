#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

int main()
{
    int a, b, c, x, y; cin >> a >> b >> c >> x >> y;

    int price = INT_MAX;

    for (int i = 0; i <= 100000; i++) {
        price = min(price, (i * 2 * c + max(0, x - i) * a + max(0, y - i) * b));
    }

    cout << price << endl;
    return 0;
}