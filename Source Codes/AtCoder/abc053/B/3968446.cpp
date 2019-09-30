#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string s;
    cin >> s;

    int l = s.size();
    int si = 0;
    int ei = l;
    for(int i = 0; i < l; ++i)
    {
        if(s[i] == 'A')
        {
            si = i;
            break;
        }
    }
    for(int i = l - 1; i >= 0; --i)
    {
        if(s[i] == 'Z')
        {
            ei = i;
            break;
        }
    }

    cout << ei - si + 1 << endl;
    return 0;
}