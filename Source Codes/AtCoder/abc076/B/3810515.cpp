#include <iostream>

using namespace std;

int main(void)
{
    int N, K;
    cin >> N >> K;

    int n;
    int ans = 1;
    for(n = 0; n < N; ++n)
    {
        if(ans >= K)
            break;

        ans *= 2;
    }
    for(; n < N; ++n)
    {
        ans += K;
    }
    cout << ans << endl;
    return 0;
}