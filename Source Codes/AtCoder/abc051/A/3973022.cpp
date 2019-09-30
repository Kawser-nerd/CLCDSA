#include <iostream>

using namespace std;

int main(void)
{
    string s;
    cin >> s;

    s[5] = ' ';
    s[13] = ' ';
    cout << s << endl;
    return 0;
}