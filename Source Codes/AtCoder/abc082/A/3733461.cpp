#include <iostream>

using namespace std;

int main(void)
{
    int a, b;
    cin >> a >> b;
    int c = a + b;
    cout << (c / 2) + (c & 1) << endl;
    return 0;
}