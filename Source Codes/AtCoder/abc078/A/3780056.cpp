#include <iostream>

using namespace std;

int main(void)
{
    char X, Y;
    cin >> X >> Y;

    if(X < Y) cout << '<';
    else if(X > Y) cout << '>';
    else cout << '=';
    cout << endl;
    return 0;
}