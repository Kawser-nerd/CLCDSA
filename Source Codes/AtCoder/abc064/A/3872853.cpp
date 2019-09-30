#include <iostream>

using namespace std;

int main(void)
{
    int r, g, b;
    cin >> r >> g >> b;
    cout << ((r * 100 + g * 10 + b) % 4 ? "NO" : "YES") << endl;
    return 0;
}