#include <iostream>

using namespace std;

int main(void)
{
    uint32_t A, B, C;
    cin >> A >> B >> C;


    uint32_t ans = 0;
    if(B >= C)
    {
        ans = 2 * C + (B - C);
    }
    else if(B < C)
    {
        ans = 2 * B;
        C -= B;
        if(A >= C)
        {
            ans += C;
        }
        else if(A < C)
        {
            ans += A + 1;
        }
    }


    cout << ans << endl;

    return 0;
}