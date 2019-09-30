#include <iostream>

using namespace std;

int main()
{
    int a, b; cin >> a >> b;
    if (b == 0) cout << a << endl;
    else        cout << ((a + b) % 24) << endl;
    return 0;
}