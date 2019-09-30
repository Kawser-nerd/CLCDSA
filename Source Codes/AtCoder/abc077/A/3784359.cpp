#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string c1, c2;
    cin >> c1 >> c2;
    char tmp = c2[2];
    c2[2] = c2[0];
    c2[0] = tmp;

    cout << (c1 == c2 ? "YES" : "NO") << endl;
    return 0;
}