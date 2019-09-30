#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a, b, c; cin >> a >> b >> c;
    cout << (*--end(a) == *begin(b) && *--end(b) == *begin(c) ? "YES" : "NO") << endl;
    return 0;
}