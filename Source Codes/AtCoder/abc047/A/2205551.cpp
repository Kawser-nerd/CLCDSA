#include <iostream>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    cout << ((a + b == c || b + c == a || c + a == b)? "Yes" : "No") << endl;

    return 0;
}