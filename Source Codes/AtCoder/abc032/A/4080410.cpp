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
    int a, b, n;
    cin >> a >> b >> n;

    int xa = n / a;
    int xb = n / b;
    int ans = 0;
    while(1)
    {
        int na = xa * a;
        int nb = xb * b;
        if(na >= n && na == nb)
        {
            ans = na;
            break;
        }
        na > nb ? xb++ : xa++;
    }
    cout << ans << endl;
    return 0;
}