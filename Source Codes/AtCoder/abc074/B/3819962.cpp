#include <iostream>

using namespace std;

int main(void)
{
    int N, K;
    cin >> N >> K;

    int ans = 0;
    for(int i = 0; i < N; ++i)
    {
        int xi;
        cin >> xi;
        ans += 2 * min(xi, K - xi);
    }

    cout << ans << endl;
    return 0;
}