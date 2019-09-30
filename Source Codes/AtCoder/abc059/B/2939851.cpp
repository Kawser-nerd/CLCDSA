#include <iostream>

using namespace std;

int main()
{
    double a, b; cin >> a >> b;
    cout << (a == b ? "EQUAL" : (a > b ? "GREATER" : "LESS")) << endl;

    return 0;
}