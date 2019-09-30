#include <cstdlib>
#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    string N;
    cin >> N;

    int l = N.size();
    if (l == 1)
    {
        cout << N << endl;
        return 0;
    }

    bool all_nine = false;
    if (N[0] == '1')
    {
        for (int i = 0; i < l; ++i)
        {
            all_nine = N[i] == '9';
        }
        if (all_nine)
        {
            cout << 1 + 9 * (l - 1) << endl;
        }
        else
        {
            cout << 9 * (l - 1) << endl;
        }
    }
    else
    {
        for (int i = 0; i < l; ++i)
        {
            all_nine = N[i] == '9';
        }
        if (all_nine)
        {
            cout << stoi(N.substr(0, 1)) + 9 * (l - 1) << endl;
        }
        else
        {
            cout << stoi(N.substr(0, 1)) - 1 + 9 * (l - 1) << endl;
        }
    }

    return 0;
}