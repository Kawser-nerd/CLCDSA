#include <iostream>

using namespace std;

int main(void)
{
    int N;

    cin >> N;

    int ans, dp, dc;
    for(int div = 100; div > 1; div /= 10)
    {
        dp = N / div;
        dc = (N % div) / (div / 10);
        if(dp > dc)
        {
            ans = dp;
            break;
        }
        else if(dp < dc)
        {
            ans = dp + 1;
            break;
        }
        else
        {
            ans = dp;
        }
        N %= div;
    }

    cout << ans << ans << ans << endl;

    return 0;
}