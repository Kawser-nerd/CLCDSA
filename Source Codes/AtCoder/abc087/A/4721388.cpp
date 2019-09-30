#include <iostream>

using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int x, a, b, c;
    cin >> x >> a >> b;
    c = x - a;
    cout << c % b << endl;

    return 0;
}