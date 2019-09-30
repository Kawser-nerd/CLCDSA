#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a, b, c; cin >> a >> b >> c;
    cout << (*--a.end() == *b.begin() && *--b.end() == *c.begin() ? "YES" : "NO") << endl;
    return 0;
}