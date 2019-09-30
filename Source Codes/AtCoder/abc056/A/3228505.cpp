#include <iostream>

using namespace std;

int main()
{
    char a, b; cin >> a >> b;
    cout << ((a == 'H' && b == 'H') ? 'H' : (a == 'H' && b == 'D' ? 'D' : (a == 'D' && b == 'H' ? 'D' : 'H'))) << endl;
    // if (a == 'H' && b == 'H') cout << 'H' << endl;
    // else if (a == 'H' && b == 'D') cout << 'D' << endl;
    // else if (a == 'D' && b == 'H') cout << 'D' << endl;
    // else cout << 'H' << endl;
    return 0;
}