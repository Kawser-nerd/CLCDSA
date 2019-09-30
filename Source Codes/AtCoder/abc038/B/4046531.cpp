#include <iostream>

using namespace std;

int main(void)
{
    int H1, W1, H2, W2;
    cin >> H1 >> W1 >> H2 >> W2;

    string ans = "NO";
    if(H1 == H2 || H1 == W2 || H2 == W1 || W1 == W2)
        ans = "YES";

    cout << ans << endl;
    return 0;
}