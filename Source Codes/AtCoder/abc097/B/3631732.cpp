#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
    int X;
    cin >> X;

    int ans = 1;
    for(int b = 2; b < X; ++b)
    {
        int p = 2;
        int tmp_ans = 1;
        while(1)
        {
            int exp = (int)pow(b, p);
            if(X < exp)
            {
                break;
            }
            tmp_ans = max(tmp_ans, exp);
            ++p;
        }
        ans = max(ans, tmp_ans);
    }

    cout << ans << endl;

    return 0;
}