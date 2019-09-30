#include <iostream>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (a + b + 1 >= c)
    {
        cout << b + c << endl;
    }
    else
    {
        cout << a + 2*b + 1 << endl;
    }
    return 0;
}