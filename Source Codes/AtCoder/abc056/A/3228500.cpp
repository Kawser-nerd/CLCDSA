#include <iostream>

using namespace std;

int main()
{
    char a, b; cin >> a >> b;
    if (a == 'H' && b == 'H') cout << 'H' << endl;
    else if (a == 'H' && b == 'D') cout << 'D' << endl;
    else if (a == 'D' && b == 'H') cout << 'D' << endl;
    else cout << 'H' << endl;
    return 0;
}