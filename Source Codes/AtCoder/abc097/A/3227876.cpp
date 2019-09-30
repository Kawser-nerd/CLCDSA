#include <iostream>

using namespace std;

int main()
{
    int a, b, c, d; cin >> a >> b >> c >> d;
    cout << ((abs(a - b) <= d && abs(b - c) <= d) || abs(a - c) <= d ? "Yes" : "No") << endl;
    return 0;
}