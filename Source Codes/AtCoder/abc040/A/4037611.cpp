#include <iostream>

using namespace std;

int main(void)
{
    int n, x;
    cin >> n >> x;

    double d = (n - 1) / 2.0;
    if(d > (x - 1))
        cout << x - 1 << endl;
    else
        cout << (n - 1) - (x - 1) << endl;
    return 0;
}