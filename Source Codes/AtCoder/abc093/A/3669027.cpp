#include <iostream>

using namespace std;

int main(void)
{
    bool abc[3] = {false, false, false};

    for(int i = 0; i < 3; ++i)
    {
        char c;
        cin >> c;
        if(abc[c - 'a'])
        {
            cout << "No" << endl;
            return 0;
        }
        abc[c - 'a'] = true;
    }
    cout << "Yes" << endl;
    return 0;
}