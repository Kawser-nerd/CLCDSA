#include <iostream>

using namespace std;

int main(void)
{
    int N;

    cin >> N;

    int ans = 0;
    if(11 <= N)
    {
        if(!(N & 1)) N--;

        for(int n = N; n > 11; n -= 2)
        {
            int divisor = 1;
            for(int ni = n; ni > 2; ni -= 2)
            {
                if(!(n % ni)) divisor++;
            }
            if(8 == divisor) ans++;
        }
    }

    cout << ans << endl;

    return 0;
}