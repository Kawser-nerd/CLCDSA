#include <iostream>
using namespace std;

int main(void)
{
    int a, b, c;
    cin >> a >> b >> c;
    for (int i = 1; i <= 100; i++)
    {
        if ((a * i) % b == c)
        {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}