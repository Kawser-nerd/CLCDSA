#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    long long x, y;
    long long ans = 0;

    cin >> x >> y;

    if(x <= y)
    {
        if(x*y >= 0)
        {
            ans = abs(abs(x) - abs(y));
        }
        else
        {
            if(abs(x) < abs(y))
            {
                ans = 1 + y + x;
            }
            else
            {
                ans = 1 + abs(abs(x) - abs(y));
            }
        }
    }
    else
    {
        if(abs(x) < abs(y))
        {
            if(x < 0)
            {
                ans = 1 + abs(abs(y) - abs(x)) + 1;
            }
            else
            {
                ans = 1 + abs(abs(y) - abs(x));
            }
        }
        else
        {
            if(y <= 0)
            {
                ans = 1 + abs(abs(x) - abs(y));
            }
            else
            {
                ans = 1 + abs(abs(x) - abs(y)) + 1;
            }
        }
    }

    cout << ans << endl;

    return 0;
}