#include <iostream>

using namespace std;

int main(void)
{
    int A, B, C, X;
    cin >> A >> B >> C >> X;

    int ans = 0;
    for(int a = min(A, X / 500); a >= 0; --a)
    {
        if(0 == (X - (500 * a)))
        {
            ans++;
            continue;
        }
        for(int b = min(B, (X - (500 * a)) / 100); b >= 0; --b)
        {
            if(0 == (X - (500 * a) - (100 * b)))
            {
                ans++;
                continue;
            }
            for(int c = min(C, (X - (500 * a) - (100 * b)) / 50); c >= 0; --c)
            {
                if(0 == (X - (500 * a) - (100 * b) - (50 * c)))
                {
                    ans++;
                    continue;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}