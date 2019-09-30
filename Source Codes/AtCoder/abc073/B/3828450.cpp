#include <iostream>

using namespace std;

int main(void)
{
    int N;
    cin >> N;
    int ans = 0;
    for(int i = 0; i < N; ++i)
    {
        int li, ri;
        cin >> li >> ri;
        ans += ri - li + 1;
    }
    cout << ans << endl;
    return 0;
}