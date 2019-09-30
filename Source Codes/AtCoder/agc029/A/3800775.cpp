#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string S;
    cin >> S;

    uint64_t ans = 0;
    int firstb = 0;
    bool foundb = false;
    for(int i = 0; i < S.length() - 1; ++i)
    {
        if(S[i] == 'B')
        {
            firstb = i;
            foundb = true;
            break;
        }
    }

    if(foundb)
    {
        int w = 0;
        for(int i = firstb + 1; i < S.length(); ++i)
        {
            if(S[i] == 'W')
            {
                ans += i - firstb - w;
                w++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}