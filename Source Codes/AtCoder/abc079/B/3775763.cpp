#include <iostream>

using namespace std;

int main(void)
{
    int N;
    cin >> N;

    uint64_t ans = 0;
    if(N == 1)
        ans = 1;
    else if(N == 2)
        ans = 3;
    else
    {
        uint64_t Li_1 = 3;
        uint64_t Li_2 = 1;
        uint64_t Li = 0;//Li_1 + Li_2;
        for(int i = 3; i <= N; ++i)
        {
            Li = Li_1 + Li_2;
            Li_2 = Li_1;
            Li_1 = Li;
        }
        ans = Li;
    }

    cout << ans << endl;
    return 0;
}