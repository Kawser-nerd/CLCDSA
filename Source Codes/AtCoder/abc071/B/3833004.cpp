#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string S;
    cin >> S;

    string s = "abcdefghijklmnopqrstuvwxyz";
    for(const auto& e : S)
    {
        s[e - 'a'] = 0;
    }
    for(const auto& e : s)
    {
        if(e)
        {
            cout << e << endl;
            return 0;
        }
    }
    cout << "None" << endl;
    return 0;
}