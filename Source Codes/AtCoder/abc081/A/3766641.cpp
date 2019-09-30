#include <iostream>

using namespace std;

int main(void)
{
    int ans = 0;
    for(int i = 0; i < 3; ++i)
    {
        char si;
        cin >> si;
        ans += si - '0';
    }
    cout << ans << endl;
    return 0;
}