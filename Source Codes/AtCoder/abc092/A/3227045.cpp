#include <iostream>

using namespace std;

int main()
{
    int a, b, c, d; cin >> a >> b >> c >> d;

    if (a >= b && c >= d)      cout << b + d << endl;
    else if (a >= b && c <= d) cout << b + c << endl;
    else if (a <= b && c >= d) cout << a + d << endl;
    else                       cout << a + c << endl;

    return 0;
}