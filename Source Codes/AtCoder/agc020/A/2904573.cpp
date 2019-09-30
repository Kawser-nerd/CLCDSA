#include <iostream>

using namespace std;

int main()
{
    int n, a, b; cin >> n >> a >> b;
    if ((b - a) % 2 == 0) cout << "Alice" << endl;
    else                cout << "Borys" << endl;

    return 0;
}