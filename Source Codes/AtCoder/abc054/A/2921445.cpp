#include <iostream>

using namespace std;

int main() 
{
    int a, b; cin >> a >> b;
    if (a == b) cout << "Draw" << endl;
    else if (a == 1)      cout << "Alice" << endl;
    else if (b == 1)      cout << "Bob" << endl;
    else                  cout << (a > b ? "Alice" : "Bob") << endl;
    return 0;
}