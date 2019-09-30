#include <iostream>
#include <string>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    int a_pos = 0;
    int z_pos = 0;
    for (auto itr = s.begin(); itr != s.end(); ++itr, ++a_pos)
    {
        if (*itr == 'A')
        {
            break;
        }
    }

    for (auto itr = s.end(); itr != s.begin(); --itr, ++z_pos)
    {
        if (*itr == 'Z')
        {
            break;
        }
    }

    cout << s.length() - a_pos - z_pos + 1 << endl;

    return 0;
}