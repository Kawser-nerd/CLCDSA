#include <iostream>
using namespace std;
int gcd(int x, int y)
{
    if (y == 0)
        return x;
    return gcd(y, x % y);
}

int main()
{
    int n, ans = 0, a;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>a;
        ans = gcd(ans, a);
    }
    cout<<ans<<'\n';
    return 0;
}