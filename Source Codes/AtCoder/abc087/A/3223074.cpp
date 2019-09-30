#include <iostream>

using namespace std;

int main()
{
    int x, a, b; cin >> x >> a >> b;
    cout << (x - a) - ((x - a) / b) * b << endl;
    return 0;
}