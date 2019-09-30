#include <iostream>

using namespace std;

int main(void)
{
    int X, t;
    cin >> X >> t;
    cout << max(0, X - t) << endl;
    return 0;
}