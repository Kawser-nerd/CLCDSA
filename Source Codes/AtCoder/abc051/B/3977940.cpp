#include <iostream>

using namespace std;

int main(void)
{
    int K, S;
    cin >> K >> S;

    int ans = 0;
    for(int x = 0; x <= K; ++x)
    {
        for(int y = 0; y <= K; ++y)
        {
            int z = S - x - y;
            if((0 <= z) && (z <= K))
                ans++;
        }
    }
    cout << ans << endl;
    return 0;
}