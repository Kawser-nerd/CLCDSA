#include <iostream>

using namespace std;

int main(void)
{
    int ans = 700;
    for(int i = 0; i < 3; ++i)
    {
        char order;
        cin >> order;
        if('o' == order)
            ans += 100;
    }
    cout << ans << endl;
    return 0;
}