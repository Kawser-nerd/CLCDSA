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
    string S;
    int T;
    cin >> S >> T;

    int x = 0;
    int y = 0;
    int q = 0;
    for(const auto& e : S)
    {
        switch(e)
        {
        case 'L':
            x--;
            break;
        case 'R':
            x++;
            break;
        case 'U':
            y++;
            break;
        case 'D':
            y--;
            break;
        default:
            q++;
            break;
        }
    }

    int ans = 0;
    if(T == 1)
    {
        vector<int> v(4);
        v[0] = abs(x + q) + abs(y);
        v[1] = abs(x - q) + abs(y);
        v[2] = abs(x) + abs(y + q);
        v[3] = abs(x) + abs(y - q);
        sort(v.begin(), v.end());
        ans = v[3];
    }
    else
    {
        while(q)
        {
            q--;
            int ax = abs(x);
            int ay = abs(y);
            if(ax >= ay)
            {
                x += (x > 0 ? -1 : 1);
            }
            else if(ax < ay)
            {
                y += (y > 0 ? -1 : 1);
            }
            else
            {
                y--;
            }
        }
        ans = abs(x) + abs(y);
    }

    cout << ans << endl;

    return 0;
}