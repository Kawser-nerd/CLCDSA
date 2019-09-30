#include <iostream>

using namespace std;

int main(void)
{
    int N;
    cin >> N;
    int ans = 33;
    for(int i = 0; i < N; ++i)
    {
        int ai;
        cin >> ai;
        int tmp = 0;
        while(!(ai & (1 << tmp)))
            tmp++;
        ans = min(ans, tmp);
    }

    cout << ans << endl;
    return 0;
}