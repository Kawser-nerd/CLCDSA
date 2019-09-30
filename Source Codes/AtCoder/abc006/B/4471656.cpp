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
    uint64_t n;
    cin >> n;
    vector<uint64_t> v = {0, 0, 1};

    uint64_t ans = 0;
    if(n <= 3)
    {
        ans = v[n - 1];
    }
    else
    {
        for(uint64_t i = 4; i < n; ++i)
        {
            uint64_t an = (v[2] + v[1] + v[0]) % 10007;
            v[0] = v[1];
            v[1] = v[2];
            v[2] = an;
        }
        ans = v[2] + v[1] + v[0];
    }

    cout << ans % 10007 << endl;

    return 0;
}