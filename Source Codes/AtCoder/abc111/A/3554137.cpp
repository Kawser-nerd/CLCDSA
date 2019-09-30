#include <iostream>

using namespace std;

int main(void)
{
    int n;

    cin >> n;

    int div = 100;
    for(int i = 0; i < 3; ++i)
    {
        cout << 10 - (n / div);
        n %= div;
        div /= 10;
    }
    cout << endl;

    return 0;
}