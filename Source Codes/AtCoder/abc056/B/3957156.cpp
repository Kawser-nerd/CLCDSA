#include <iostream>

using namespace std;

int main(void)
{
    int W, a, b;
    cin >> W >> a >> b;

    int aw = a + W;
    int bw = b + W;
    int ans = 0;
    if(a < b)
    {
        ans = max(b - aw, 0);
    }
    else if(a >= b)
    {
        ans = max(a - bw, 0);
    }

    cout << ans << endl;
    return 0;
}