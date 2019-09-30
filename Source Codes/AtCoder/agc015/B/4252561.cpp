#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <queue>
#include <set>

using namespace std;

string S;

long long ans = 0;

int main()
{
    cin >> S;

    long long len = S.length();

    for(int f = 1;f <= len;f++)
    {
        if(S[f - 1] == 'U')
        {
            ans +=  2 * (f - 1) + len - f;
        }
        else
        {
            ans += f - 1 + 2 * (len - f);
        }
    }

    cout << ans << endl;

    return 0;
}