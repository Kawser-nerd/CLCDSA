#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string S;
    cin >> S;

    int l = S.length();
    for(int i = l - 2; i >= 0; i -= 2)
    {
        string s0 = S.substr(0, i / 2);
        string s1 = S.substr(i / 2, i / 2);
        if(s0 == s1)
        {
            cout << i << endl;
            break;
        }
    }
    return 0;
}