#include <iostream>

using namespace std;
int X, Y;
int ans;
int main()
{
    cin >> X >> Y;
    ans = X + (Y >> 1);
    cout << ans << endl;
}