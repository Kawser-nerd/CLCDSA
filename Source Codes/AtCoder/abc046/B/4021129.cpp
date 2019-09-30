#include <iostream>

using namespace std;

int main(void)
{
    uint32_t N, K;
    cin >> N >> K;

    uint32_t ans = K;
    for(uint32_t i = 1; i < N; ++i)
    {
        ans *= (K - 1);
    }
    cout << ans << endl;
    return 0;
}