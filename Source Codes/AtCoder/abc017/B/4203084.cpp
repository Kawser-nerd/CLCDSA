#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void)
{
    string X;
    cin >> X;

    bool ans = true;

    if(*X.rbegin() == 'c')
    {
        ans = false;
    }
    else
    {
        for(int i = 0; i < X.size(); ++i)
        {
            if(X[i] == 'c')
            {
                if(X[++i] != 'h')
                {
                    ans = false;
                }
            }
            else if(X[i] != 'o' && X[i] != 'k' && X[i] != 'u')
            {
                ans = false;
                break;
            }
        }
    }
    cout << (ans ? "YES" : "NO") << endl;
    return 0;
}