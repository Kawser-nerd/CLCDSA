#include <iostream>

using namespace std;

int main(void)
{
    int n;
    cin >> n;

    int ans = 1000000;
    for(int i = 1; i < 10000; ++i)
    {
        for(int j = 1; j < 10000; ++j)
        {
            if((i * j) <= n)
            {
                ans = min(ans, abs(i - j) + (n - i * j));
            }
        }
    }
    cout << ans << endl;
    return 0;
}