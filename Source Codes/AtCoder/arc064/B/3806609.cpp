#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int p = s.length() % 2;
    bool f = (s[0] == s[s.length() - 1]);

    if((p == 0 && f == true) || (p == 1 && f == false))
    {
        cout << "First" << endl;
    }
    else
    {
        cout << "Second" << endl;
    }


    return 0;
}