#include <iostream>

using namespace std;

int main()
{
    int a, b, x; cin >> a >> b >> x;
    cout << (x >= a && b >= x - a ? "YES" : "NO") << endl;
    return 0;
}