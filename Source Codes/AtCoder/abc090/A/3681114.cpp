#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string s[3];
    cin >> s[0];
    cin >> s[1];
    cin >> s[2];

    cout << s[0][0];
    cout << s[1][1];
    cout << s[2][2];
    cout << endl;
    return 0;
}