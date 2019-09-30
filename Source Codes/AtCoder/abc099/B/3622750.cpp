#include <iostream>

using namespace std;

int main(void)
{
    int a, b; cin >> a >> b;

    cout << int(double(b - a) / 2.0f * ((b - a) + 1)) - b << endl;
    return 0;
}