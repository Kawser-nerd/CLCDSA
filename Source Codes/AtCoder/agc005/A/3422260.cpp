#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int l = s.length();
    int cs = 0;
    int ct = 0;
    int c = 0;
    for (int i = 0; i < l; i++)
    {
        if(s[i] == 'S')
        {
            cs++;
        }
        else
        {
            if(cs >= 1)
            {
                c++;
            }
            cs = max(0, cs - 1);
        }
    }

    cout << l - c * 2 << endl;

    return 0;
}