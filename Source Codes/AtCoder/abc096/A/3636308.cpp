#include <iostream>

using namespace std;

int main(void)
{
    int a, b;
    cin >> a >> b;
    cout << (a <= b ? a : a - 1) << endl;
    return 0;
}